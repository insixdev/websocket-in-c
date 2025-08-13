#include <libwebsockets.h>

static int callbackClient(struct lws *wsi, enum lws_callback_reasons reason, void *user, void *in, size_t len);
extern struct lws_client_connect_info info;
void mainConection();



