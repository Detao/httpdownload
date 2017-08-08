/* -*- encoding: utf-8; -*- */
/* -*- c-mode -*- */
/* File-name:    <url.h> */
/* Author:       <Xsoda> */
/* Create:       <Friday December 20 12:47:08 2013> */
/* Time-stamp:   <Wednesday December 25, 10:9:18 2013> */
/* Mail:         <Xsoda@Live.com> */

#ifndef __OAL_URL_H__
#define __OAL_URL_H__

/*
 * parse url like this
 *
 * schema://username:password@host:port/path?key=value#fragment
 * \____/   \______/ \______/ \__/ \__/ \__/ \_______/ \______/
 *   |         |        |       |    |    |      |         |
 * schema      |     password   |   port  |    query    fragment
 *          username          host      path
 *
 * note:
 *   - username, password, port, path, query, fragment is optional.
 *   - scheme, host must be setting.
 *   - username and password must be paired.
 *
 */

typedef enum
{
   HOST_IPV4,
   HOST_IPV6,
   HOST_DOMAIN
} host_type_t;

typedef struct _url_field
{
   host_type_t host_type;
   char *href;
   char *schema;
   char *username;
   char *password;
   char *host;
   char *port;
   char *path;
   char *dir;
   char *filename;
   char *fileextname;
   int query_num;
   struct {
      char *name;
      char *value;
   } *query;
   char *fragment;
} OAL_URL_FIELD;

#ifdef __cplusplus
extern "C" {
#endif
// parse api
OAL_URL_FIELD *OAL_urlParse(const char *str);
char *OAL_urlParseValue(OAL_URL_FIELD *url, const char *key);
void OAL_urlFree(OAL_URL_FIELD *url);

// generate api
char *OAL_urlCreate(const char *protocol, 
	const char *username, const char *password, 
	const int ip, const int port, const char *path);
int OAL_urlAppendKeyValueStr(char **url, const char *key, const char *value);
int OAL_urlAppendKeyValueInt(char **url, const char *key, const int value);

#ifdef __cplusplus
}
#endif

#endif /* !__URI_H__ */
