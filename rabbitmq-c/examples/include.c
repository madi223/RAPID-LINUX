#ifndef librabbitmq_examples_utils_h
#define librabbitmq_examples_utils_h
#endif
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <rabbitmq-c/amqp.h>
#include <rabbitmq-c/tcp_socket.h>

#include <assert.h>
#include "utils.h"
#include <ctype.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <rabbitmq-c/amqp.h>
#include <rabbitmq-c/framing.h>
#include <stdint.h>
int main(){
 amqp_socket_t *socket = NULL;
  amqp_connection_state_t conn;
  conn = amqp_new_connection();

  socket = amqp_tcp_socket_new(conn);
printf("I AM JUST A DUMMY TEST \n");
}
