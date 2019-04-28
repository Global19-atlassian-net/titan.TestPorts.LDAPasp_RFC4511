/******************************************************************************
* Copyright (c) 2000-2019 Ericsson Telecom AB
* All rights reserved. This program and the accompanying materials
* are made available under the terms of the Eclipse Public License v2.0
* which accompanies this distribution, and is available at
* https://www.eclipse.org/org/documents/epl-2.0/EPL-2.0.html
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
//  File:               LDAPmsg_RFC4511_PT.cc
//  Description:        LDAP_RFC4511 test port source code
//  Rev:                R4A
//  Prodnr:             CNL 113 513   
//

#include <ctype.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "LDAPasp_RFC4511_PT.hh"

namespace LDAPasp__RFC4511__PortType {

using namespace LDAPasp__RFC4511__Types;

LDAPasp__RFC4511__PT::LDAPasp__RFC4511__PT(const char *par_port_name)
#ifdef AS_USE_SSL
  : SSL_Socket("LDAP", par_port_name)
#else
  : Abstract_Socket("LDAP", par_port_name)
#endif  
  , LDAPasp__RFC4511__PT_BASE(par_port_name)
{
	set_ttcn_buffer_usercontrol(true);
        decode_incoming_message = true;
}

LDAPasp__RFC4511__PT::~LDAPasp__RFC4511__PT()
{

}

const char* LDAPasp__RFC4511__PT::local_port_name()
{
        return "local_port";
}

const char* LDAPasp__RFC4511__PT::remote_address_name()
{
        return "remote_address";
}

const char* LDAPasp__RFC4511__PT::local_address_name()
{
        return "local_address";
} // not used in the tesport

const char* LDAPasp__RFC4511__PT::remote_port_name()
{
        return "remote_port";
}

const char* LDAPasp__RFC4511__PT::halt_on_connection_reset_name()
{ 
        return "halt_on_connection_reset";
}

const char* LDAPasp__RFC4511__PT::server_mode_name()
{
        return "server_mode";
}

const char* LDAPasp__RFC4511__PT::socket_debugging_name()
{
        return "socket_debugging";
}

const char* LDAPasp__RFC4511__PT::nagling_name()
{
        return "nagling";
}

const char* LDAPasp__RFC4511__PT::server_backlog_name()
{
        return "server_backlog";
}

const char* LDAPasp__RFC4511__PT::use_connection_ASPs_name()
{
        return "use_connection_ASPs";
}

const char* LDAPasp__RFC4511__PT::decode_incoming_message_name()
{
        return "decode_incoming_message";
}

const char* LDAPasp__RFC4511__PT::use_non_blocking_socket_name()
{
        return "use_non_blocking_socket";
}

const char* LDAPasp__RFC4511__PT::ssl_use_ssl_name()
{
        return "ssl_use_ssl";
}

const char* LDAPasp__RFC4511__PT::ssl_use_session_resumption_name()
{
        return "ssl_use_session_resumption";
}

const char* LDAPasp__RFC4511__PT::ssl_private_key_file_name()
{
        return "ssl_private_key_file";
}

const char* LDAPasp__RFC4511__PT::ssl_trustedCAlist_file_name()
{
        return "ssl_trustedCAlist_file";
}

const char* LDAPasp__RFC4511__PT::ssl_certificate_file_name()
{
        return "ssl_certificate_chain_file";
}

const char* LDAPasp__RFC4511__PT::ssl_password_name()
{
        return "ssl_private_key_password";
}

const char* LDAPasp__RFC4511__PT::ssl_cipher_list_name()
{
        return "ssl_allowed_ciphers_list";
}

const char* LDAPasp__RFC4511__PT::ssl_verifycertificate_name()
{
        return "ssl_verify_certificate";
}


void LDAPasp__RFC4511__PT::set_parameter(const char *parameter_name,
				const char *parameter_value)
{
        log_debug("entering LDAPasp__RFC4511__PT::set_parameter(%s, %s)",
                      parameter_name, parameter_value);
        if(!parameter_set(parameter_name ,parameter_value)) {
                if(!strcasecmp(parameter_name, decode_incoming_message_name())){
                        if(!strcasecmp(parameter_value, "yes"))
                                decode_incoming_message = true;
                        else if (!strcasecmp(parameter_value, "no"))
                                decode_incoming_message = false;
                else log_error("Parameter value '%s' not recognized for paramete"
                                "r '%s'", parameter_value,
                                decode_incoming_message_name());
                }
                else log_warning("LDAPasp__RFC4511__PT::set_parameter(): "
                                "Unsupported Test Port parameter: %s",
                                parameter_name);
        }
        log_debug("leaving LDAPasp__RFC4511__PT::set_parameter(%s, %s)",
                        parameter_name, parameter_value);
}

void LDAPasp__RFC4511__PT::Handle_Fd_Event(int fd,
  boolean is_readable, boolean is_writable, boolean is_error)
{
        log_debug("entering LDAPasp__RFC4511__PT::Handle_Fd_Event()");
        Handle_Socket_Event(fd, is_readable, is_writable, is_error);
        log_debug("leaving LDAPasp__RFC4511__PT::Handle_Fd_Event()");
}

void LDAPasp__RFC4511__PT::Handle_Timeout(double time_since_last_call)
{
        log_debug("entering LDAPasp__RFC4511__PT::Handle_Timeout()");
        Handle_Timeout_Event(time_since_last_call);
        log_debug("leaving LDAPasp__RFC4511__PT::Handle_Timeout()");
}

void LDAPasp__RFC4511__PT::message_incoming(const unsigned char* msg,
                                                int messageLength,
                                                int client_id) {
        log_debug("entering LDAPasp__RFC4511__PT::message_incoming()");

        TTCN_Buffer * buf_p = get_buffer(client_id);

        while (buf_p->contains_complete_TLV()) {
                log_debug("Incoming buffer has been filled with"
                        "a complete TLV");
                if (!decode_incoming_message){
                        size_t TLV_length = get_TLV_length(buf_p->get_data(), buf_p->get_len());
                        if (TLV_length == 0) return;
                        incoming_message(OCTETSTRING(TLV_length, 
                                                        buf_p->get_data()));
                        buf_p->set_pos(TLV_length);
                        buf_p->cut();
                        continue;
                }
                Lightweight__Directory__Access__Protocol::LDAPMessage msg;
                msg.decode(Lightweight__Directory__Access__Protocol::LDAPMessage_descr_, *buf_p, TTCN_EncDec::CT_BER,
                      BER_ACCEPT_ALL);
                buf_p->cut();

                ASP__LDAP__msg parameters_ASP_LDAP;
                parameters_ASP_LDAP.data() = msg;
                parameters_ASP_LDAP.client__id() = client_id;
                incoming_message(parameters_ASP_LDAP);
        } 

        log_debug("leaving LDAPasp__RFC4511__PT::message_incoming()");
}

void LDAPasp__RFC4511__PT::user_map(const char *system_port)
{
        log_debug("entering LDAPasp__RFC4511__PT::user_map()");
        map_user();
        log_debug("leaving LDAPasp__RFC4511__PT::user_map()");
}

void LDAPasp__RFC4511__PT::user_unmap(const char *system_port)
{
        log_debug("entering LDAPasp__RFC4511__PT::user_unmap()");
        unmap_user();
        log_debug("leaving LDAPasp__RFC4511__PT::user_unmap()");
}

void LDAPasp__RFC4511__PT::user_start()
{
}

void LDAPasp__RFC4511__PT::user_stop()
{
}

void LDAPasp__RFC4511__PT::outgoing_send(const ASP__LDAP__msg& send_par)
{
         log_debug("entering LDAPasp__RFC4511__PT::outgoing_send()");
         ASP__LDAP__msg msg_copy = send_par;

         TTCN_Buffer buf;
         msg_copy.data().encode(Lightweight__Directory__Access__Protocol::LDAPMessage_descr_, buf, TTCN_EncDec::CT_BER,
		        BER_ENCODE_DER);

         if(msg_copy.client__id().ispresent()) {
                send_outgoing(buf.get_data(), buf.get_len(),
                                msg_copy.client__id()());
         } else {
                send_outgoing(buf.get_data(), buf.get_len());
         }

         log_debug("leaving LDAPasp__RFC4511__PT::outgoing_send()");
}

void LDAPasp__RFC4511__PT::outgoing_send(const ASP__LDAP__shutdown& send_par)
{
        log_debug("entering LDAPasp__RFC4511__PT::outgoing_send(ASP__LDAP__shutdown)");

        close_listen_port();

        log_debug("leaving LDAPasp__RFC4511__PT::outgoing_send(ASP__LDAP__shutdown)");

}

void LDAPasp__RFC4511__PT::outgoing_send(const ASP__LDAP__connect& send_par)
{
        log_debug("entering LDAPasp__RFC4511__PT::"
                        "outgoing_send(ASP__LDAP__connect)");

		char remotePort[6];
		char localPort[6];
		const char* localHostname = NULL;
		char* localServicename = NULL;

		sprintf(remotePort, "%d", (int)send_par.portnumber());

        if(send_par.local__hostname().is_bound() && 
                        send_par.local__hostname().ispresent())
		{
			localHostname = send_par.local__hostname()();
		}
        else
        {
			localHostname = get_local_host_name();
			if(localHostname)
                log_debug("using local host name configured in %s: %s",
                                local_address_name(), localHostname);
       		 else
        	{
        		log_debug("using 'localhost' as local host name");
        	}
		}

        if(send_par.local__portnumber().is_bound() && 
                        send_par.local__portnumber().ispresent())
		{
			sprintf(localPort, "%d", (int)send_par.local__portnumber()());
			localServicename = localPort;
		}
        else if(get_local_port_number() > 0)
        {
                log_debug("using local port number configured in %s: %d",
                                local_port_name(), get_local_port_number());
				sprintf(localPort, "%d", get_local_port_number());
				localServicename = localPort;
        }
        else
        {
                log_debug("using random local port number");
        }

        open_client_connection(send_par.hostname(), remotePort, localHostname, localServicename);

        log_debug("leaving LDAPasp__RFC4511__PT::"
                        "outgoing_send(ASP__LDAP__connect)");

}

void LDAPasp__RFC4511__PT::outgoing_send(const ASP__LDAP__listen& send_par)
{
        log_debug("entering LDAPasp__RFC4511__PT::"
                        "outgoing_send(ASP__LDAP__listen)");

		char localPort[7];
		const char* localServicename = NULL;
		const char* localHostname = NULL;


        if(send_par.local__hostname().is_bound() &&
                        send_par.local__hostname().ispresent())
                localHostname = send_par.local__hostname()();
        else
		{
			localHostname = get_local_host_name();
			if(localHostname)
			{ 
				log_debug("using local host name configured in %s: %s",
                                local_address_name(), get_local_host_name());
			} else
			{
                log_debug("using 'localhost' as local host name");
			}
        }

        if(send_par.portnumber().is_bound() && 
                        send_par.portnumber().ispresent())
		{
			sprintf(localPort, "%d", (int)send_par.portnumber()());

			localServicename = (const char*)&localPort;
		}
        else if(get_local_port_number() > 0)
        {
                log_debug("using local port number configured in %s: %d",
                                local_port_name(), get_local_port_number());
				sprintf(localPort, "%d", get_local_port_number());
				localServicename = localPort;
        }
        else
        {
                log_debug("using random local port number");
        }

        open_listen_port(localHostname, localServicename);

        log_debug("leaving LDAPasp__RFC4511__PT::"
                        "outgoing_send(ASP__LDAP__listen)");
}

void LDAPasp__RFC4511__PT::outgoing_send(const ASP__LDAP__close& send_par)
{
        log_debug("entering LDAPasp__RFC4511__PT::"
                        "outgoing_send(ASP__LDAP__close)");

        if(send_par.client__id().is_bound() && 
                        send_par.client__id().ispresent())
                remove_client((int)send_par.client__id()());
        else
                remove_all_clients();

        log_debug("leaving LDAPasp__RFC4511__PT::"
                        "outgoing_send(ASP__LDAP__close)");

}

size_t LDAPasp__RFC4511__PT::get_TLV_length(const unsigned char* data, size_t length){
    
    
        enum position {TAG,LENGTH,INDEFINITE};

        position pos = TAG;
        size_t number_of_L_bytes = 0;
        size_t leng = 0;

        for (size_t i = 0; i < length; ){
                switch(pos){
                        case TAG:{
                                if ((data[i] & 0x1F) > 30){
                                        ++i;
                                        for ( ;(i < length) && (data[i] & 0x80); ++i);
                                }

                                ++i;
                                pos = LENGTH;
                                break;

                        }
                        case LENGTH:{
                                if (data[i] & 0x80){
                                        if (! (data[i] & 0x7F)) //indefinite form
                                                pos = INDEFINITE;
                                        else{ //long form
                                                number_of_L_bytes = data[i] & 0x7F;
                                                ++i;
                                                for(;(i < length) && number_of_L_bytes; ++i, --number_of_L_bytes){
                                                  leng<<=8;
                                                  leng+=data[i];
                                                }
                                                
                                                if (i >= length || leng + i > length) goto not_complete;
                                                
                                                return leng + i;
                                                  
                                        }
                                } else{ //short form
                                        if (i + data[i] + 1 > length)
                                                goto not_complete;
                                        else
                                                return i + data[i] + 1;
                                }
                                
                                ++i;
                                break;
                        }
                        case INDEFINITE:{
                                if ( i + 1 < length && !data[i] && !data[i+1])
                                  return i + 2;
                                
                                int j = get_TLV_length(&data[i], length - i);
                                if (!j) return 0;
                                i+=j;
                                break;
                        }
                        default:
                                log_error("Unknown state while parsing TLV.");
                }
        }

not_complete:
        log_warning("LDAPasp__RFC4511__PT::"
                        "get_TLV_length: there was no complete TLV "
                        "in the buffer from the reading position.");
        return 0;
};

void LDAPasp__RFC4511__PT::peer_connected(int client_id, const char *host, const int port)
{
        log_debug("entering LDAPasp__RFC4511__PT::peer_connected(%d, %s, %d)",
                        client_id, host, port);

        if (get_use_connection_ASPs()){
                ASP__LDAP__connected message_incoming;
                
				message_incoming.client__id() = client_id;
                message_incoming.client__address() = host;
                message_incoming.portnumber() = port;

                incoming_message(message_incoming);
        }

        log_debug("leaving LDAPasp__RFC4511__PT::peer_connected()");
}


void LDAPasp__RFC4511__PT::peer_disconnected(int client_id)
{
        log_debug("entering LDAPasp__RFC4511__PT::peer_disconnected()");

        if (get_use_connection_ASPs()){
            ASP__LDAP__closed message_incoming;

            message_incoming.client__id() = client_id;

            incoming_message(message_incoming);
        }
        else Abstract_Socket::peer_disconnected(client_id);
        log_debug("leaving LDAPasp__RFC4511__PT::peer_disconnected()");
}

void LDAPasp__RFC4511__PT::listen_port_opened(int port_number)
{
        log_debug("entering LDAPasp__RFC4511__PT::listen_port_opened(%d)",
                        port_number);

        if(get_use_connection_ASPs())
        {
                ASP__LDAP__listen__result message_incoming;
                message_incoming.portnumber() = port_number;
                incoming_message(message_incoming);
        }
        else Abstract_Socket::listen_port_opened(port_number);

        log_debug("leaving LDAPasp__RFC4511__PT::listen_port_opened()");
}

void LDAPasp__RFC4511__PT::client_connection_opened(int client_id){

        log_debug("entering LDAPasp__RFC4511__PT::client_connection_opened(%d)",
                        client_id);

        if(get_use_connection_ASPs())
        {
                ASP__LDAP__connect__result message_incoming;

                message_incoming.client__id() = client_id;
                incoming_message(message_incoming);
        }
        else Abstract_Socket::client_connection_opened(client_id);
        log_debug("leaving LDAPasp__RFC4511__PT::client_connection_opened(%d)",
                        client_id);

}

}//namespace
