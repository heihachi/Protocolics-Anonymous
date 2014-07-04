// $Id: page20.html,v 1.3 1998/10/27 19:05:56 jcej Exp $

#ifndef CRYPT_H
#define CRYPT_h

#include "ProtocolTask.h"
#include "ace/Log_Msg.h"

/* An interface (adaptor) between your favorite encryption method and
   an ACE_Stream.
*/
class Crypt : public Protocol_Task
{
public:

    typedef Protocol_Task inherited;

        // Again we have the option of multiple threads and again I
        // regret tempting folks to use it.
    Crypt( int _thr_count = 0 );

    ~Crypt(void);

protected:

        // Moving downstream will encrypt the data
     int send(ACE_Message_Block *message,
              ACE_Time_Value *timeout);

        // And moving upstream will decrypt it.
     int recv(ACE_Message_Block *message,
              ACE_Time_Value *timeout);
};

#endif // CRYPT_H