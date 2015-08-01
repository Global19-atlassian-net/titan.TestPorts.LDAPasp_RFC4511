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
//  File:               LDAPasp_RFC4511_PT.hh
//  Description:        LDAPasp_RFC4511 test port header
//  Rev:                R4A
//  Prodnr:             CNL 113 513
//


#ifndef LDAPasp__RFC4511__PT_HH
#define LDAPasp__RFC4511__PT_HH

#include "LDAPasp_RFC4511_PortType.hh"
#include "Abstract_Socket.hh"

#include "Lightweight_Directory_Access_Protocol.hh"

namespace LDAPasp__RFC4511__PortType {

//LDAPasp__RFC4511__Types
#ifdef AS_USE_SSL
class LDAPasp__RFC4511__PT : public SSL_Socket,
                                public LDAPasp__RFC4511__PT_BASE {
#else
  class LDAPasp__RFC4511__PT : public Abstract_Socket,
                                public LDAPasp__RFC4511__PT_BASE {
#endif
  public:
    LDAPasp__RFC4511__PT(const char *par_port_name=NULL);
    ~LDAPasp__RFC4511__PT();

    void set_parameter(const char *parameter_name, const char *parameter_value);

  protected:
    void user_map(const char *system_port);
    void user_unmap(const char *system_port);

    void user_start();
    void user_stop();

    void outgoing_send(const LDAPasp__RFC4511__Types::ASP__LDAP__msg& send_par);
    void outgoing_send(const LDAPasp__RFC4511__Types::ASP__LDAP__shutdown& send_par);
    void outgoing_send(const LDAPasp__RFC4511__Types::ASP__LDAP__connect& send_par);
    void outgoing_send(const LDAPasp__RFC4511__Types::ASP__LDAP__listen& send_par);
    void outgoing_send(const LDAPasp__RFC4511__Types::ASP__LDAP__close& send_par);

    void message_incoming(const unsigned char*, int length, int client_id);
    void Add_Fd_Read_Handler(int fd) { Handler_Add_Fd_Read(fd); }
    void Add_Fd_Write_Handler(int fd) { Handler_Add_Fd_Write(fd); }
    void Remove_Fd_Read_Handler(int fd) { Handler_Remove_Fd_Read(fd); }
    void Remove_Fd_Write_Handler(int fd) { Handler_Remove_Fd_Write(fd); }
    void Remove_Fd_All_Handlers(int fd) { Handler_Remove_Fd(fd); }
    void Handler_Uninstall() { Uninstall_Handler(); }
    void Timer_Set_Handler(double call_interval, boolean is_timeout = TRUE,
      boolean call_anyway = TRUE, boolean is_periodic = TRUE) {
      Handler_Set_Timer(call_interval, is_timeout, call_anyway, is_periodic);
    }
    
    void peer_connected(int client_id, const char* host, const int port);
    void peer_disconnected(int client_id);
    
    void listen_port_opened(int port_number); //used only in case of errors
    void client_connection_opened(int client_id);

    const char* local_port_name();
    const char* remote_address_name();
    const char* local_address_name();
    const char* remote_port_name();
    const char* halt_on_connection_reset_name();
    const char* server_mode_name();
    const char* socket_debugging_name();
    const char* nagling_name();
    const char* server_backlog_name();
    const char* ssl_use_ssl_name();
    const char* ssl_use_session_resumption_name();
    const char* ssl_private_key_file_name();
    const char* ssl_trustedCAlist_file_name();
    const char* ssl_certificate_file_name();
    const char* ssl_password_name();
    const char* ssl_cipher_list_name();
    const char* ssl_verifycertificate_name();
    const char* use_non_blocking_socket_name();
    const char* use_connection_ASPs_name();
    const char* decode_incoming_message_name();

  private:
    void Handle_Fd_Event(int fd, boolean is_readable, boolean is_writable, boolean is_error);
    void Handle_Timeout(double time_since_last_call);

    TTCN_Buffer incoming_buffer;

    //test port parameters
    bool decode_incoming_message;
    
    
    size_t get_TLV_length(const unsigned char* data, size_t length);
  };

}//namespace

#endif
