#ifndef WEBSOCKET_H
#define WEBSOCKET_H

#include <libwebsockets.h>
/*
* @brief: funcion manejara los eventos de lws
* @param arg: argumento
* @return: NULL
*/
void mainWebsocket();
/*
* @brief: funcion que manejara los eventos de lws
* @param wsi: puntero a la estructura lws
* @param reason: reason de lws
* @param user: usuario
* @param in: mensaje/datos entrantes
* @param len: longitud del mensaje
* @return: 0
*/
static int chat_callback(struct lws *wsi, enum lws_callback_reasons reason, void *user, void *in, size_t len);

/*
* @brief: funcion que obtendra el contexto de lws
* @return: contexto de lws
*/
struct lws_context * getWebsocketContext();

#endif
