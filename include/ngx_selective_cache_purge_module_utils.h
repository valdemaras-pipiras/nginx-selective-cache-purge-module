#ifndef _NGX_SELECTIVE_CACHE_PURGE_UTILS_H_
#define _NGX_SELECTIVE_CACHE_PURGE_UTILS_H_

#include <ngx_selective_cache_purge_module.h>

ngx_str_t *ngx_selective_cache_purge_alloc_str(ngx_pool_t *pool, uint len);
static ngx_int_t  ngx_selective_cache_purge_send_response_text(ngx_http_request_t *r, const u_char *text, uint len, ngx_flag_t last_buffer);
ngx_int_t  ngx_selective_cache_purge_send_response(ngx_http_request_t *r, u_char *data, size_t len, ngx_uint_t status, ngx_str_t *content_type);
ngx_str_t *ngx_selective_cache_purge_get_module_type_by_tag(void *tag);

ngx_selective_cache_purge_cache_item_t *ngx_selective_cache_purge_file_info_lookup(ngx_rbtree_t *tree, ngx_http_file_cache_node_t *fcn);

ngx_http_file_cache_node_t *ngx_selective_cache_purge_file_cache_lookup(ngx_http_file_cache_t *cache, u_char *key);
ngx_int_t                   ngx_selective_cache_purge_file_cache_lookup_on_disk(ngx_http_request_t *r, ngx_http_file_cache_t *cache, ngx_str_t *cache_key, u_char *key);

void ngx_selective_cache_purge_rbtree_zones_insert(ngx_rbtree_node_t *temp, ngx_rbtree_node_t *node, ngx_rbtree_node_t *sentinel);
void ngx_selective_cache_purge_rbtree_file_info_insert(ngx_rbtree_node_t *temp, ngx_rbtree_node_t *node, ngx_rbtree_node_t *sentinel);

static void ngx_selective_cache_purge_timer_reset(ngx_msec_t timer_interval, ngx_event_t *timer_event);
void ngx_selective_cache_purge_timer_set(ngx_msec_t timer_interval, ngx_event_t *event, ngx_event_handler_pt event_handler, ngx_flag_t start_timer);

static void ngx_selective_cache_purge_rbtree_walker(ngx_rbtree_t *tree, ngx_rbtree_node_t *node, void *data, ngx_int_t (*apply) (ngx_rbtree_node_t *node, void *data));

#endif /* _NGX_SELECTIVE_CACHE_PURGE_UTILS_H_ */
