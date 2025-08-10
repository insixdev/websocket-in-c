#include <websocket.h>

/* los protocolos que se van a usar en el servidor
 * en este caso solo se va a usar http, ya que libwebsocket soporta varios protocolos
 * en este caso se va a usar el protocolo http para manejar las peticiones
 * 
*/
const struct lws_protocols protocol[] = {
    {
        "chat", // nombre del protocolo
        lws_callback_http_dummy,
        0, // datos per session
        0, // tamaño de los datos per session
    },
    { NULL, NULL, 0, 0 } /* terminator */
};
void* mainWebsocket(void* arg) {
    struct lws_context *context = getWebsocketContext();
    if (context == NULL){
        printf("Error al crear el contexto de lws\n");
        return NULL;
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
    memset(&info, 0, sizeof(info)); // Limpiar la memoria para mayor seguridad

    // Configuracion del servidor
    info.port = 8090;
    info.protocols = protocol;
    info.gid = -1;
    info.uid = -1;


    struct lws_context *context = lws_create_context(&info);

    if (context == NULL) {
        printf("Error al crear el contexto de lws\n");
        return NULL;
    }
    
    return context;
}


static int chat_callback(struct lws *wsi, enum lws_callback_reasons reason, void *user, void *in, size_t len) {
    switch (reason) {
        case LWS_CALLBACK_HTTP:
            // Manejar la solicitud HTTP
            break;
        case LWS_CALLBACK_RECEIVE:
            // Manejar el mensaje recibido
            break;
        case LWS_CALLBACK_SERVER_WRITEABLE:
            // Manejar el mensaje recibido
            break;
        case LWS_CALLBACK_CLOSED:
            // Manejar el mensaje recibido
            break;
        default:
            break;
    }
    return 0;
}
