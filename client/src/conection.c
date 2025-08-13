#include "conection.h"

void mainConection(){
    // struct that holds connection info for the websocket client
    struct lws_client_connect_info info;
    struct lws_context_creation_info ctx_info;
    struct lws_context *context;

    memset(&ctx_info, 0, sizeof(ctx_info));

    ctx_info.port = CONTEXT_PORT_NO_LISTEN;
    ctx_info.protocols = (struct lws_protocols[]) {
        {"chat",callbackClient,0,0,

        },
        {NULL,NULL,0,0,}
    };
    context = lws_create_context(&ctx_info);
    if(context == NULL){
        printf("Error creating context\n");
        return;
    }
    memset(&info, 0, sizeof(info));
    info.context = context;
    info.address = "127.0.0.1";
    info.port = 8090;
    info.path = "/";
    info.host = "127.0.0.1";
    info.origin = "127.0.0.1";
    info.protocol = "websocket";
    //bucle principal
    while(lws_service(context, 0)>=0){
    
    }
    lws_context_destroy(context);
    
}
static int callbackClient(struct lws *wsi, enum lws_callback_reasons reason, void *user, void *in, size_t len){
    switch (reason)
    {
    case LWS_CALLBACK_CLIENT_ESTABLISHED:
        printf("Client connected\n");
        //send message
        lws_callback_on_writable(wsi);
        break;
    case LWS_CALLBACK_CLIENT_WRITEABLE:
        char *msg;
        msg = "Hello server";
        //send message, len of message, type of message
        lws_write(wsi, (unsigned char *)msg, strlen(msg), LWS_WRITE_TEXT);
        break;
    case LWS_CALLBACK_CLIENT_RECEIVE:
        printf("Client received: %s\n",(int)len, (char *)in);
        break;
    case LWS_CALLBACK_CLIENT_CLOSED:
        printf("Client closed\n");
        break;
    default:
        break;
    }
    return 0;
}

