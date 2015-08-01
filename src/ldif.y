%{
/******************************************************************************
* Copyright (c) 2006, 2015  Ericsson AB
* All rights reserved. This program and the accompanying materials
* are made available under the terms of the Eclipse Public License v1.0
* which accompanies this distribution, and is available at
* http://www.eclipse.org/legal/epl-v10.html
*
* Contributors:
* Gergely Futo
* Attila Balasko
* Csaba Feher
* Csaba Fehér
* Gabor Szalai
* Janos Kovesdi
* Szabolcs Balazs Beres
* Szabolcs Béres
* Zoltan Medve
******************************************************************************/
//
//  File:               ldif.y
//  Description:        LDIF definition file
//  Rev:                R4A
//  Prodnr:             CNL 113 513
//
#include <stdio.h>
#include <string.h>
#include "LDIF_RFC4511.hh"
#include "memory.h"

using namespace LDIF__RFC4511;

extern int ldif_lex();
extern void ldif_error(const char *s);
extern void ldif_restart(FILE* input_file);

int line_number = 0;
boolean error_recovery = false;
LDIFData temporal_data;
AttrValRecord temporal_AttrValRecord;
LDIFControl temporal_Control;
ChangeModifyData temporal_changemodifydata;
int AttrValRecord_Counter = 0;
int option_counter = 0;
int data_counter = 0;
int control_counter = 0;
int modification_counter = 0;
boolean erroneous;
boolean inner_resolve_env;

%}
%union {
	CHARSTRING *string_val;
}
%start ldif_file
%token SEP
%token DN COLON SAFE_STRING SAFE_BASE64_STRING
%token GREATER SEMICOLON HYPHEN
%token FLOAT_VAL INTEGER_VAL BISON_CONTROL
%token BISON_TRUE BISON_FALSE CHANGETYPE
%token ADD DELETE MODRDN MODDN NEWRDN DELETEOLDRDN
%token ADD_COLON DELETE_COLON
%token NEWSUPERIOR MODIFY REPLACE
%token URL_STRING ZERO ONE LDAP_OID
%token CHAR_ATTRIBUTE_TYPE
%%

ldif_file:
  version_spec ldif_end
| ldif_end
  {
    temporal_data.version() = OPTIONAL<INTEGER>(OMIT_VALUE);
  }
;

ldif_end:
  ldif_attrval_record optional_separators ldif_end
| ldif_attrval_record ldif_end
| ldif_attrval_record
| ldif_change_record optional_separators ldif_end
| ldif_change_record ldif_end
| ldif_change_record
;
    
optional_separators:
  SEP optional_separators
| SEP
;

ldif_attrval_record : 
  dn_spec SEP attrval_specs
;

attrval_specs :
  attrval_specs attrval_spec
    { 
      temporal_data.datalist()[data_counter-1].data().content()
        [AttrValRecord_Counter++] = temporal_AttrValRecord;
    }
| attrval_spec
    {
      temporal_data.datalist()[data_counter-1].data().content()
        [AttrValRecord_Counter++] = temporal_AttrValRecord;
    }
;

ldif_change_record :
  dn_spec SEP controls changerecord
;

controls : 
  controls control 
    {
       temporal_data.datalist()[data_counter - 1].data().change()
         .controllist() [control_counter++] = temporal_Control;
    }
| 
    {
       temporal_data.datalist()[data_counter-1].data().change()
         .controllist().set_size(0);
    }
;

version_spec :
  CHAR_ATTRIBUTE_TYPE COLON SAFE_STRING optional_separators
    {
       if (CHARSTRING("version") == *($<string_val>1))
       {
         const char* strValue = *($<string_val>3);
         int version = atoi(strValue);
         
         1 == version ? temporal_data.version() = 1 : temporal_data.version() = OPTIONAL<INTEGER>(OMIT_VALUE);
       }else{
         temporal_data.version() = OPTIONAL<INTEGER>(OMIT_VALUE);
       }
       delete $<string_val>1;
       delete $<string_val>3;
    }
| CHAR_ATTRIBUTE_TYPE COLON error optional_separators 
    {
       TTCN_warning("Version error at line %d",line_number);
       error_recovery = false;
       erroneous = true;
       delete $<string_val>1;
    }
| CHAR_ATTRIBUTE_TYPE COLON SAFE_STRING error SEP
    {
       TTCN_warning("Version error at line %d",line_number);
       erroneous = true;
       
       delete $<string_val>1;
       delete $<string_val>3;
    }
| error SEP
    {
       TTCN_warning("Version error at line %d",line_number);
       error_recovery = false;
       erroneous = true;
    }
;
    
dn_spec : 
  DN SAFE_STRING
    {
       AttrValRecord_Counter = 0;
       modification_counter = 0;
       control_counter = 0;
       option_counter = 0;



       if(!inner_resolve_env)
       {
         temporal_data.datalist()[data_counter++].dn__string()
           = *($<string_val>2);
       }else{
         CHARSTRING temp_char = CHARSTRING(*($<string_val>2));
         int index = 0;
         int start_pos = 0;
         int char_length = temp_char.lengthof();

         /*search for the first '$'*/
         for(; index < char_length && temp_char[index] != '$'; index++){}

         /*create the charstring from string till first '$'*/
         temporal_data.datalist()[data_counter].dn__string()
            = substr(temp_char,0,index);

         /*If there is some possible environment variable*/
         while(index < char_length)
         {
           start_pos = index++;
           unsigned int temp_ascii = char2int(temp_char[index]);
           char *env_val = NULL;
           // the first character of the id shall be a letter
           if ((temp_ascii >= 65 && temp_ascii <= 90) ||     /*A..Z*/
               (temp_ascii >= 97 && temp_ascii <= 122))      /*a..z*/
           {
             do
             {/*Search the full environment variable*/
               env_val = mputc(env_val, (char)temp_ascii);
               index++;
               if(index < char_length)
                 temp_ascii = char2int(temp_char[index]);
               else
                 temp_ascii = 0;
             } while ((temp_ascii >= 65 && temp_ascii <= 90) ||  /*A..Z*/
                      (temp_ascii >= 97 && temp_ascii <= 122) || /*a..z*/
                      (temp_ascii >= 48 && temp_ascii <= 57) ||  /*0..9*/
                       temp_ascii == 95);                        /*_   */
             char* temp = getenv((const char*)env_val);
             if(temp == NULL)
             {/*Environment variable not found. store as $something*/
               TTCN_warning("%s could not be resolved",(const char*)(env_val));
               temporal_data.datalist()[data_counter].dn__string()
                 = temporal_data.datalist()[data_counter].dn__string()
                   + substr(temp_char,start_pos,index-start_pos);
             }
             else
             {/*replace environment variable with its value*/
               temporal_data.datalist()[data_counter].dn__string()
                 = temporal_data.datalist()[data_counter].dn__string()
                   + temp;
             }
             start_pos = index;
             Free(env_val);
           }
           /*search for the next '$'*/
           for(; index < char_length && temp_char[index] != '$'; index++){}

           if(start_pos < char_length)
             /*complete the charstring from string till next '$'*/
             temporal_data.datalist()[data_counter].dn__string()
               = temporal_data.datalist()[data_counter].dn__string()
                 + substr(temp_char,start_pos,index-start_pos);
         }
         data_counter++;
       }



       delete $<string_val>2;
    } 
| DN COLON SAFE_BASE64_STRING
    {
       AttrValRecord_Counter = 0;
       modification_counter = 0;
       control_counter = 0;
       option_counter = 0;
       temporal_data.datalist()[data_counter++].dn__string() 
         = *($<string_val>3);
       delete $<string_val>3;
    }
| DN error 
    {
       TTCN_warning("Wrong format for the dn at line %d",line_number);
       error_recovery = false;
       AttrValRecord_Counter = 0;
       modification_counter = 0;
       control_counter = 0;
       option_counter = 0;
       temporal_data.datalist()[data_counter++].dn__string() 
         = "ERROR";
       erroneous = true;
    }
| DN COLON error 
    {
       TTCN_warning("Wrong format for the dn at line %d",line_number);
       error_recovery = false;
       AttrValRecord_Counter = 0;
       modification_counter = 0;
       control_counter = 0;
       option_counter = 0;
       temporal_data.datalist()[data_counter++].dn__string() 
         = "ERROR";
       erroneous = true;
    }
;

control : 
  BISON_CONTROL ldap_oid control_mid control_end SEP 
    {
       temporal_Control.ldapoid() = *($<string_val>2);
       delete $<string_val>2;
    }
| BISON_CONTROL error control_mid control_end SEP 
    {
       if(!error_recovery)
       {
         TTCN_warning("ldap_oid error at line %d",line_number);
         error_recovery = true;
       }
       temporal_Control.ldapoid() = "0";
       erroneous = true;
    }
| BISON_CONTROL ldap_oid control_mid control_end error 
    {
       if(!error_recovery)
       {
         TTCN_warning("line number %d contains more than one data", line_number);
         error_recovery = true;
       }
       temporal_Control.ldapoid() = "0";
       erroneous = true;
    }
;

control_mid : 
  BISON_TRUE
    {
       temporal_Control.criticality() = true;
    }
| BISON_FALSE
    {
       temporal_Control.criticality() = false;
    }
| 
    {
       temporal_Control.criticality() = OPTIONAL<BOOLEAN>(OMIT_VALUE);
    }
;

control_end :
  COLON value_spec 
    {
       if (temporal_AttrValRecord.attributevalue()().ischosen(ValueUnion::ALT_safe__string)){
        temporal_Control.controlvalue() = 
          OCTETSTRING(temporal_AttrValRecord.attributevalue()().safe__string().lengthof(),
                      (const unsigned char*)(const char*)temporal_AttrValRecord.attributevalue()().safe__string());
       }else if (temporal_AttrValRecord.attributevalue()().ischosen(ValueUnion::ALT_base64__string)){
        temporal_Control.controlvalue() = 
          OCTETSTRING(temporal_AttrValRecord.attributevalue()().base64__string().lengthof(),
                      (const unsigned char*)(const char*)temporal_AttrValRecord.attributevalue()().base64__string());
       }else{
        temporal_Control.controlvalue() = 
          OCTETSTRING(temporal_AttrValRecord.attributevalue()().url().lengthof(),
                      (const unsigned char*)(const char*)temporal_AttrValRecord.attributevalue()().url());
       }
    }
| 
    {
       temporal_Control.controlvalue() = OPTIONAL<OCTETSTRING>(OMIT_VALUE);
    }
;

ldap_oid :
  FLOAT_VAL
    {
       $<string_val>$ = $<string_val>1;
    }
| INTEGER_VAL
    {
       $<string_val>$ = $<string_val>1;
    }
| LDAP_OID
    {
       $<string_val>$ = $<string_val>1;
    }
;

attrval_spec : 
  AttributeDescription COLON value_spec SEP
| AttributeDescription COLON SEP      
    {
      temporal_AttrValRecord.attributevalue()().safe__string()
        = "";
    }
| error COLON value_spec SEP
    {
      if(!error_recovery){
        TTCN_warning("Attribute error at line %d",line_number);
        error_recovery = true;
      }
      temporal_AttrValRecord.attributetype() = CHARSTRING("ERROR");
      temporal_AttrValRecord.optionlist().set_size(0);
      temporal_AttrValRecord.attributevalue()().safe__string()
         = CHARSTRING("ERROR");
      erroneous = true;
    }
| error COLON SEP
    {
      if(!error_recovery){
        TTCN_warning("Attribute error at line %d",line_number);
        error_recovery = true;
      }
      temporal_AttrValRecord.attributetype() = CHARSTRING("ERROR");
      temporal_AttrValRecord.optionlist().set_size(0);
      temporal_AttrValRecord.attributevalue()().safe__string()
         = CHARSTRING("ERROR");
      erroneous = true;
    }
| AttributeDescription error value_spec SEP
    {
       TTCN_warning("Attribute must be separated from value with colon at line %d",line_number);
       error_recovery = false;
       erroneous = true;
    }
| AttributeDescription COLON error SEP
    {
       TTCN_warning("Value error at line %d",line_number);
       error_recovery = false;
       temporal_AttrValRecord.attributevalue()().safe__string() 
         = CHARSTRING("ERROR");
       erroneous = true;
    }
;

value_spec :
  SAFE_STRING
    {


       if(!inner_resolve_env)
       {
         temporal_AttrValRecord.attributevalue()().safe__string()
           = CHARSTRING(*($<string_val>1));
       }else{
         CHARSTRING temp_char = CHARSTRING(*($<string_val>1));
         int index = 0;
         int start_pos = 0;
         int char_length = temp_char.lengthof();

         /*search for the first '$'*/
         for(; index < char_length && temp_char[index] != '$'; index++){}

         /*create the charstring from string till first '$'*/
         temporal_AttrValRecord.attributevalue()().safe__string()
            = substr(temp_char,0,index);

         /*If there is some possible environment variable*/
         while(index < char_length)
         {
           start_pos = index++;
           unsigned int temp_ascii = char2int(temp_char[index]);
           char *env_val = NULL;
           /*The first character of the id shall be a letter*/
           if ((temp_ascii >= 65 && temp_ascii <= 90) ||     /*A..Z*/
               (temp_ascii >= 97 && temp_ascii <= 122))      /*a..z*/
           {
             do
             {/*Search the full environment variable*/
               env_val = mputc(env_val, (char)temp_ascii);
               index++;
               if(index < char_length)
                 temp_ascii = char2int(temp_char[index]);
               else
                 temp_ascii = 0;
             } while ((temp_ascii >= 65 && temp_ascii <= 90) ||  /*A..Z*/
                      (temp_ascii >= 97 && temp_ascii <= 122) || /*a..z*/
                      (temp_ascii >= 48 && temp_ascii <= 57) ||  /*0..9*/
                       temp_ascii == 95);                        /*_   */
             char* temp = getenv((const char*)env_val);
             if(temp == NULL)
             {/*Environment variable not found. store as $something*/
               TTCN_warning("%s could not be resolved",(const char*)(env_val));
               temporal_AttrValRecord.attributevalue()().safe__string()
                 = temporal_AttrValRecord.attributevalue()().safe__string()
                   + substr(temp_char,start_pos,index-start_pos);
             }
             else
             {/*replace environment variable with its value*/
               temporal_AttrValRecord.attributevalue()().safe__string()
                 = temporal_AttrValRecord.attributevalue()().safe__string()
                   + temp;
             }
             start_pos = index;
	     Free(env_val);
           }
           /*search for the next '$'*/
           for(; index < char_length && temp_char[index] != '$'; index++){}

           if(start_pos < char_length)
             /*complete the charstring from string till next '$'*/
             temporal_AttrValRecord.attributevalue()().safe__string()
               = temporal_AttrValRecord.attributevalue()().safe__string()
                 + substr(temp_char,start_pos,index-start_pos);
         }
       }




       delete $<string_val>1;
    }
| COLON SAFE_BASE64_STRING
    {
       temporal_AttrValRecord.attributevalue()().base64__string() 
         = *($<string_val>2);
       delete $<string_val>2;
    }
| GREATER URL_STRING
    {
       temporal_AttrValRecord.attributevalue()().url() = *($<string_val>2);
       delete $<string_val>2;
    }
;

AttributeDescription : 
  AttributeType options
    {
      temporal_AttrValRecord.attributetype() = *($<string_val>1);
      delete $<string_val>1;
    }
| AttributeType
    {
      temporal_AttrValRecord.attributetype() = *($<string_val>1);
      delete $<string_val>1;
    }
| error options
    {
      if(!error_recovery)
      {
        TTCN_warning("Attribute error at line %d",line_number);
        error_recovery = true;
      }
      temporal_AttrValRecord.attributetype() = CHARSTRING("ERROR");
      erroneous = true;
    }
;

AttributeType :
  ldap_oid
    {
      $<string_val>$ = $<string_val>1;
      option_counter = 0;
      temporal_AttrValRecord.optionlist().set_size(0);
    }
| CHAR_ATTRIBUTE_TYPE
    {
      $<string_val>$ = $<string_val>1;
      option_counter = 0;
      temporal_AttrValRecord.optionlist().set_size(0);
    }
;

options : 
  SEMICOLON CHAR_ATTRIBUTE_TYPE
    {
      temporal_AttrValRecord.optionlist()[option_counter++] = *($<string_val>2);
      delete $<string_val>2;
    }
| SEMICOLON INTEGER_VAL
    {
      temporal_AttrValRecord.optionlist()[option_counter++] = *($<string_val>2);
      delete $<string_val>2;
    }
| options SEMICOLON INTEGER_VAL
    {
      temporal_AttrValRecord.optionlist()[option_counter++] = *($<string_val>3);
      delete $<string_val>3;
    }
| options SEMICOLON CHAR_ATTRIBUTE_TYPE
    {
      temporal_AttrValRecord.optionlist()[option_counter++] = *($<string_val>3);
      delete $<string_val>3;
    }
| SEMICOLON error
    {
      if(!error_recovery)
      {
        TTCN_warning("Wrong option syntax at line %d",line_number);
        error_recovery = true;
      }
      temporal_AttrValRecord.optionlist()[option_counter++] = "ERROR";
      erroneous = true;
    }
;
    
changerecord : 
  CHANGETYPE changerecord_end 
    {
      if(error_recovery)
        error_recovery = false;
    }
;

changerecord_end : 
  change_add
| change_delete
| change_modify	
| change_moddn
;

change_add : 
  ADD SEP change_add_end
| ADD SEP error 
    {
       if(!error_recovery)
       {
         TTCN_warning("Add must be followed by at least 1 attribute:value "
           "pair at line %d",line_number);
         error_recovery = true;
       }
       temporal_data.datalist()[data_counter - 1].data().change()
         .changetype().changeadd().set_size(0);
       erroneous = true;
    }
;

change_add_end : 
  change_add_end attrval_spec
    {
       temporal_data.datalist()[data_counter - 1].data().change()
         .changetype().changeadd()[AttrValRecord_Counter++] 
       = temporal_AttrValRecord;
    }
| attrval_spec
    {
        AttrValRecord_Counter = 0;
        temporal_data.datalist()[data_counter - 1].data().change()
          .changetype().changeadd()[AttrValRecord_Counter++] 
        = temporal_AttrValRecord;
    }
;

change_delete : 
  DELETE SEP
    {
       temporal_data.datalist()[data_counter - 1].data().change()
         .changetype().changedelete().set_size(0);
    }
;

change_moddn :
  change_moddn_start SEP change_moddn_middle
  SEP DELETEOLDRDN zero_or_one SEP change_moddn_end
  
| change_moddn_start error change_moddn_middle
  SEP DELETEOLDRDN zero_or_one SEP change_moddn_end
    {
       if(!error_recovery)
       {
         TTCN_warning("line number %d contains more than one data", line_number);
         error_recovery = true;
       }
       erroneous = true;
    }
| change_moddn_start SEP change_moddn_middle
  error DELETEOLDRDN zero_or_one SEP change_moddn_end
    {
       if(!error_recovery)
       {
          TTCN_warning("line number %d contains more than one data", line_number);
          error_recovery = true;
       }
       erroneous = true;
    }
|  change_moddn_start SEP change_moddn_middle
   SEP error zero_or_one SEP change_moddn_end
    {
      if(!error_recovery)
      {
         TTCN_warning("deleteoldrdn missing from the change moddn structure"
         " ending on the %dth line",line_number-1);
         error_recovery = true;
      }
      temporal_data.datalist()[data_counter - 1].data().change()
         .changetype().changemoddn().deleteoldrdn() = false;
      erroneous = true;
    }  
|  change_moddn_start SEP change_moddn_middle
   SEP DELETEOLDRDN zero_or_one error change_moddn_end
    {
      if(!error_recovery)
      {
         TTCN_warning("line number %d contains more than one data", line_number);
         error_recovery = true;
      }
      temporal_data.datalist()[data_counter - 1].data().change()
         .changetype().changemoddn().deleteoldrdn() = false;
      erroneous = true;
    }  
;

change_moddn_start : 
  MODRDN
    {
      temporal_data.datalist()[data_counter - 1].data().change()
        .changetype().changemoddn().modtype() = CHARSTRING("MODRDN");
    }
| MODDN
    {
      temporal_data.datalist()[data_counter - 1].data().change()
        .changetype().changemoddn().modtype() = CHARSTRING("MODDN");
    }
| error 
    {
      if(!error_recovery)
      {
        TTCN_warning("Wrong moddn type at line %d",
          line_number);
        error_recovery = true;
      }
      temporal_data.datalist()[data_counter - 1].data().change()
        .changetype().changemoddn().modtype() = CHARSTRING("ERROR");
      erroneous = true;
    }
;

change_moddn_middle :
  NEWRDN SAFE_STRING
    {
      temporal_data.datalist()[data_counter - 1].data().change()
        .changetype().changemoddn().newrdn() 
        = *($<string_val>1);
      delete $<string_val>1;
    }
| NEWRDN COLON SAFE_BASE64_STRING
    {
      temporal_data.datalist()[data_counter - 1].data().change()
        .changetype().changemoddn().newrdn() 
        = *($<string_val>2);
      delete $<string_val>2;
    }
| error SAFE_STRING
    {
      if(!error_recovery)
      {
        TTCN_warning("The keyword newrdn was expected at line "
          "%d",line_number);
        error_recovery = true;
      }
      erroneous = true;
    }
| error COLON SAFE_STRING
    {
      if(!error_recovery)
      {
        TTCN_warning("The keyword newrdn was expected at line "
          "%d",line_number);
        error_recovery = true;
      }
      erroneous = true;
    }
| NEWRDN error
    {
      if(!error_recovery)
      {
        TTCN_warning("Wrong newrdn value at line %d",line_number);
        error_recovery = true;
      }
      temporal_data.datalist()[data_counter - 1].data().change()
        .changetype().changemoddn().newrdn() = "ERROR";
      erroneous = true;
    }
| NEWRDN COLON error
    {
      if(!error_recovery)
      {
        TTCN_warning("Wrong newrdn value at line %d",line_number);
        error_recovery = true;
      }
      temporal_data.datalist()[data_counter - 1].data().change()
        .changetype().changemoddn().newrdn() = "ERROR";
      erroneous = true;
    }
;

zero_or_one : 
  ZERO
    {
       temporal_data.datalist()[data_counter - 1].data().change()
         .changetype().changemoddn().deleteoldrdn() = false;
    }
| ONE 
    {
       temporal_data.datalist()[data_counter - 1].data().change()
         .changetype().changemoddn().deleteoldrdn() = true;
    }
| error 
    {
       if(!error_recovery)
       {
          TTCN_warning("Wrong deleteoldrdn value at line %d",line_number);
          error_recovery = true;
       }
       temporal_data.datalist()[data_counter - 1].data().change()
          .changetype().changemoddn().deleteoldrdn() = false;
       erroneous = true;
    }
;

change_moddn_end : 
  NEWSUPERIOR SAFE_STRING SEP
    {
      temporal_data.datalist()[data_counter - 1].data().change()
        .changetype().changemoddn().newsuperior()().distinguished() 
        = *($<string_val>2);
      delete $<string_val>2;
    }
| NEWSUPERIOR CHAR_ATTRIBUTE_TYPE SEP
    {
      temporal_data.datalist()[data_counter - 1].data().change()
        .changetype().changemoddn().newsuperior()().distinguished() 
        = *($<string_val>2);
      delete $<string_val>2;
    }
|  NEWSUPERIOR COLON SAFE_BASE64_STRING SEP
    {
      temporal_data.datalist()[data_counter - 1].data().change()
        .changetype().changemoddn().newsuperior()().base64__distinguished() 
        = *($<string_val>3);
      delete $<string_val>3;
    }
| 
    {
      temporal_data.datalist()[data_counter - 1].data().change()
        .changetype().changemoddn().newsuperior() 
        = OPTIONAL<NewSuperior>(OMIT_VALUE);
    }
| NEWSUPERIOR error SEP
    {
      if(!error_recovery)
      {
        TTCN_warning("Wrong newsuperior value at line %d",line_number);
        error_recovery = true;
      }
      temporal_data.datalist()[data_counter - 1].data().change()
        .changetype().changemoddn().newsuperior()().distinguished() 
        = "ERROR";
      erroneous = true;
    }
| NEWSUPERIOR COLON error SEP
    {
      if(!error_recovery)
      {
        TTCN_warning("Wrong newsuperior value at line %d",line_number);
        error_recovery = true;
      }
      temporal_data.datalist()[data_counter - 1].data().change()
        .changetype().changemoddn().newsuperior()().distinguished() 
        = "ERROR";
      erroneous = true;
    }
| error SAFE_STRING SEP
    {
      if(!error_recovery)
      {
        TTCN_warning("The keyword newsuperior was expected at line "
          "%d",line_number);
        error_recovery = true;
      }
      temporal_data.datalist()[data_counter - 1].data().change()
        .changetype().changemoddn().newsuperior()().distinguished() 
        = "ERROR";
      erroneous = true;      
    }
| error COLON SAFE_BASE64_STRING SEP
    {
      if(!error_recovery)
      {
        TTCN_warning("The keyword newsuperior was expected at line "
          "%d",line_number);
        error_recovery = true;
      }
      temporal_data.datalist()[data_counter - 1].data().change()
        .changetype().changemoddn().newsuperior()().distinguished() 
        = "ERROR";
      erroneous = true;      
    }
;
		
change_modify : 
  MODIFY SEP mod_spec
| MODIFY SEP 
    {
       temporal_data.datalist()[data_counter - 1].data().change()
         .changetype().changemodify().set_size(0)
    }
| MODIFY error mod_spec
    {
      if(!error_recovery)
      {
        TTCN_warning("line number %d contains more than one data", line_number);
        error_recovery = true;
      }
    }
;

mod_spec : 
  mod_spec mod_spec_start mod_spec_middle SEP optional_attrval_spec HYPHEN SEP 
    {
       temporal_data.datalist()[data_counter - 1].data().change()
         .changetype().changemodify()[modification_counter++] 
         = temporal_changemodifydata;
    }
| mod_spec_start mod_spec_middle SEP optional_attrval_spec HYPHEN SEP 
    {
       temporal_data.datalist()[data_counter - 1].data().change()
         .changetype().changemodify()[modification_counter++] 
         = temporal_changemodifydata;
    }
| error SEP optional_attrval_spec HYPHEN SEP 
    {
       temporal_data.datalist()[data_counter - 1].data().change()
         .changetype().changemodify()[modification_counter++] 
         = temporal_changemodifydata;
    }
| mod_spec_start mod_spec_middle error optional_attrval_spec HYPHEN SEP 
    {
      if(!error_recovery)
      {
        TTCN_warning("line number %d contains more than one data", line_number);
        error_recovery = true;
      }
      erroneous = true;
    }
| mod_spec_start mod_spec_middle SEP optional_attrval_spec error SEP 
    {
       if(!error_recovery)
       {
         TTCN_warning("Hyphen expected at line %d",line_number);
         error_recovery = true;
       }
       temporal_data.datalist()[data_counter - 1].data().change()
         .changetype().changemodify()[modification_counter++] 
         = temporal_changemodifydata;
         erroneous = true;
    }
;

mod_spec_middle : 
  AttributeDescription
    {
      temporal_AttrValRecord.attributevalue() =OPTIONAL<ValueUnion>(OMIT_VALUE);
      temporal_AttrValRecord.optionlist().set_size(0);
      temporal_changemodifydata.attrvalrecordlist()[0] = temporal_AttrValRecord;
      AttrValRecord_Counter = 1;
    }
| error
    {
      if(!error_recovery){
        TTCN_warning("Attribute error at line %d",line_number);
        error_recovery = true;
      }
      temporal_AttrValRecord.attributetype() = CHARSTRING("ERROR");
      temporal_AttrValRecord.optionlist().set_size(0);
      temporal_AttrValRecord.attributevalue()=OPTIONAL<ValueUnion>(OMIT_VALUE);
      temporal_changemodifydata.attrvalrecordlist()[0] = temporal_AttrValRecord;
      erroneous = true;
      yyerrok;
    }
;

mod_spec_start : 
  ADD_COLON
    {
       temporal_changemodifydata.operation() = CHARSTRING("add");
       temporal_changemodifydata.attrvalrecordlist().set_size(0);
    }
| DELETE_COLON
    {
       temporal_changemodifydata.operation() = CHARSTRING("delete");
       temporal_changemodifydata.attrvalrecordlist().set_size(0);
    }
| REPLACE
    {
       temporal_changemodifydata.operation() = CHARSTRING("replace");
       temporal_changemodifydata.attrvalrecordlist().set_size(0);
    }
| error COLON
    {
      if(!error_recovery)
      {
        TTCN_warning("Wrong modification operation name at line "
          "%d",line_number);
        error_recovery = true;
      }
      temporal_changemodifydata.operation() = CHARSTRING("ERROR");
      temporal_changemodifydata.attrvalrecordlist().set_size(0);
      erroneous = true;
      yyerrok;
    }
;

optional_attrval_spec : 
  optional_attrval_spec attrval_spec 
    {
      temporal_changemodifydata.attrvalrecordlist()
        [AttrValRecord_Counter++] = temporal_AttrValRecord;
    }
|
;

%%

void ldif_error(const char *s)
{
}

LDIF__RFC4511::LDIFData LDIF__RFC4511::f__ImportLDIF(const CHARSTRING& pl__file__name, const BOOLEAN& pl__resolve__env)
{
  temporal_data.version() = -1;
  temporal_data.datalist().set_size(0);

  extern FILE* ldif_in;
  ldif_in = fopen(pl__file__name,"r");

  if(ldif_in != NULL)
  {
     line_number = 0;
     AttrValRecord_Counter = 0;
     option_counter = 0;
     data_counter = 0;
     control_counter = 0;
     modification_counter = 0;
     erroneous = false;
     inner_resolve_env = pl__resolve__env;

     ldif_restart(ldif_in);
     if(yyparse() != 0)
     {
       temporal_data.version() = -1;
       temporal_data.datalist().set_size(0);
     }else if(erroneous)
     {
       temporal_data.version() = -1;
       temporal_data.datalist().set_size(0);
     }else{
       bool selection = temporal_data.datalist()[0].data().ischosen(LDIFChoice::ALT_content);
       for(int i = 1; i < temporal_data.datalist().size_of(); i++)
       {
         if(selection != temporal_data.datalist()[i].data().ischosen(LDIFChoice::ALT_content))
         {
           erroneous = true;
           TTCN_warning("Content and change records "
             "can not be mixed in one file");
         }
       }
       
       for(int i = 0; i < temporal_data.datalist().size_of(); i++)
       {
          if(temporal_data.datalist()[i].data().ischosen(LDIFChoice::ALT_change )
            && temporal_data.datalist()[i].data().change().changetype()
                 .ischosen(ChangeType::ALT_changemodify))
          {
             for(int j = 0;
                 j < temporal_data.datalist()[i].data().change()
                       .changetype().changemodify().size_of();
                 j++)
             {
               CHARSTRING type = temporal_data.datalist()[i].data()
                                   .change().changetype().changemodify()[j]
                                   .attrvalrecordlist()[0].attributetype();
               for(int k = 1;
                   k < temporal_data.datalist()[i].data()
                         .change().changetype().changemodify()[j]
                         .attrvalrecordlist().size_of(); 
                  k++)
               {
                 if(type != temporal_data.datalist()[i].data().change()
                             .changetype().changemodify()[j]
                             .attrvalrecordlist()[k].attributetype())
                 {
                   TTCN_warning("The %dth modified attribute's type is "
                     "different from the one described in the %dth "
                     "changerecord's %dth modify record (%s) (%s)",k,i,j,
                     (const char*)type,(const char*)temporal_data.datalist()[i]
                     .data().change().changetype().changemodify()[j]
                     .attrvalrecordlist()[k].attributetype());
                   erroneous = true;
                 }
               }
             }
          }
       }
       if(erroneous)
         temporal_data.version() = -1;
     }
  }else{
     TTCN_warning("The file %s could not be opened",(const char*)pl__file__name);
  }

  fclose(ldif_in);
  return temporal_data;	
}
