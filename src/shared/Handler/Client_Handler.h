#ifndef CLIENT_HANDLER_H 
#define CLIENT_HANDLER_H

#include "ace/Svc_Handler.h" 
#include "ace/SOCK_Stream.h"

class Client_Handler : public ACE_Svc_Handler < ACE_SOCK_STREAM, ACE_NULL_SYNCH >
{
	public:
		// Constructor... 
		Client_Handler(void);
		void destroy(void);
		int open(void *_acceptor);
		int close(u_long flags = 0);
		int handle_close(ACE_HANDLE _handle, ACE_Reactor_Mask _mask);
	protected:
		int svc(void);
		int handle_input(ACE_HANDLE _handle);
		int process(char *_rdbuf, int _rdbuf_len);
		~Client_Handler(void);
};

#endif // CLIENT_HANDLER_H