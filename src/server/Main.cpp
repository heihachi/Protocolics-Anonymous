/*

*/

#include "Handler/Client_Acceptor.h"

/*
As before, we create a simple signal handler that will set our finished
flag.  There are, of course, more elegant ways to handle program shutdown
requests but that isn't really our focus right now, so we'll just do the
easiest thing.
*/

static sig_atomic_t finished = 0;
extern "C" void handler(int)
{
	finished = 1;
}

/*
A server has to listen for clients at a known TCP/IP port.  The default ACE
port is 10002 (at least on my system) and that's good enough for what  we
want to do here.  Obviously, a more robust application would take a command
line parameter or read from a configuration file or do some other  clever
thing.  Just like the signal handler above, though, that's what we want to
focus on, so we're taking the easy way out.
*/

static const u_short PORT = ACE_DEFAULT_SERVER_PORT;

int main(int argc, char *argv[])
{
	ACE_Reactor reactor;

	Client_Acceptor peer_acceptor;

	if (peer_acceptor.open(ACE_INET_Addr(PORT), &reactor) == -1)
		ACE_ERROR_RETURN((LM_ERROR, "%p\n", "open"), -1);

	ACE_Sig_Action sa((ACE_SignalHandler)handler, SIGINT);

	ACE_DEBUG((LM_DEBUG, "(%P|%t) starting up server daemon\n"));

	while (!finished)
		reactor.handle_events();

	ACE_DEBUG((LM_DEBUG, "(%P|%t) shutting down server daemon\n"));

	return 0;
}