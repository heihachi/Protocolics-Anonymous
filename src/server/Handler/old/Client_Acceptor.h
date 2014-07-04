// $Id: client_acceptor.h,v 1.1 1998/08/30 13:38:27 jcej Exp $

#ifndef CLIENT_ACCEPTOR_H 
#define CLIENT_ACCEPTOR_H

#include "ace/Acceptor.h"
#include "ace/SOCK_Acceptor.h"
#include "ace/OS.h"
#include "client_handler.h"

typedef ACE_Acceptor < Client_Handler, ACE_SOCK_ACCEPTOR > Client_Acceptor_Base;

class Client_Acceptor : public Client_Acceptor_Base 
{ 
	public: 
        typedef Client_Acceptor_Base inherited;

        Client_Acceptor( int _thread_per_connection = 1 ) : thread_per_connection_(_thread_per_connection) 
        { 
        }

        int thread_per_connection(void) 
        {
			return this->thread_per_connection_;
		}

	protected: 
        int thread_per_connection_;

};

#endif // CLIENT_ACCEPTOR_H