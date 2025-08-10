#include "websocket.h"


void mainWebsocket() {
    struct lws_context *context = getWebsocketContext();
    if (context == NULL){
        printf("Error al crear el contexto de lws\n");
        return;
    }
    printf("Servidor websocket iniciado en el puerto 8090\n");

   
    while (1) {
        lws_service(context, 0);
    }
    lws_context_destroy(context);
    printf("Servidor websocket detenido\n");

}
struct lws_context * getWebsocketContext() {

    struct lws_context_creation_info info;
    // Configuracion del servidor
    info.port = 8090;
    info.protocols = protocols;
    info.gid = -1;
    info.uid = -1;
    memset(&info, 0, sizeof(info)); // Limpiar la memoria para mayor seguridad


    struct lws_context *context = lws_create_context(&info);
    if (context == NULL) {
        printf("Error al crear el contexto de lws\n");
        return NULL;
    } 
    return context;
}


/* los protocolos que se van a usar en el servidor
 * en este caso solo se va a usar http, ya que libwebsocket soporta varios protocolos
 * en este caso se va a usar el protocolo http para manejar las peticiones
 * 
*/
static struct lws_protocols protocols[] = {
    {
        "http-only",
        lws_callback_http_dummy,
        0,
        0,
    },
    { NULL, NULL, 0, 0 } /* terminator */
};