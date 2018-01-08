/* mod_example_config_simple.c: */
#include <stdio.h>
#include "apr_hash.h"
#include "ap_config.h"
#include "ap_provider.h"
#include "httpd.h"
#include "http_core.h"
#include "http_config.h"
#include "http_log.h"
#include "http_protocol.h"
#include "http_request.h"

static int example_handler(request_rec *r);

static void register_hooks(apr_pool_t *pool)
{
    /* Create a hook in the request handler, so we get called when a request arrives */
    ap_hook_handler(example_handler, NULL, NULL, APR_HOOK_LAST);
}

static int example_handler(request_rec *r)
{
    ap_rprintf(r, "Hello mod_example: before checks\n");

    ap_rprintf(r, "Request properties.");
    ap_rprintf(r, "<br/>filename:");
    ap_rprintf(r, r->filename);
    ap_rprintf(r, "<br/>canonical_filename:");
    ap_rprintf(r, r->canonical_filename);
    ap_rprintf(r, "<br/>parsed_uri.path:");
    ap_rprintf(r, r->parsed_uri.path);
    ap_rprintf(r, "<br/>");

    if (!r->handler || strcmp(r->handler, "example-handler")) return (DECLINED);
    ap_set_content_type(r, "text/html");
    ap_rprintf(r, "Further processing of example_handler request ...<br/>");

    return OK;
}

module AP_MODULE_DECLARE_DATA   example_module =
{
    STANDARD20_MODULE_STUFF,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    register_hooks   /* Our hook registering function */
};