#ifndef DGR_HTTP_GLOBAL_H
#define DGR_HTTP_GLOBAL_H

#ifdef __cplusplus
extern "C"
{
#endif

  #include "../../../DeliGranUtils/lib/entities/DGUString.h"
  #include "../../../DeliGranUtils/lib/entities/DGUHashTable.h"

  typedef struct DGRHttpVersions {
    string VERSION_1_0;
    string VERSION_1_1;
  } DGRHttpVersions;

  typedef struct DGRHResponsesCodes {
    unsigned int CONTINUE;
    unsigned int SWITCHING_PROTOCOLS;
    unsigned int PROCESSING;
    unsigned int EARLY_HINTS;
    unsigned int OK;
    unsigned int CREATED;
    unsigned int ACCEPTED;
    unsigned int NON_AUTHORITATIVE_INFORMATION;
    unsigned int NO_CONTENT;
    unsigned int RESET_CONTENT;
    unsigned int PARTIAL_CONTENT;
    unsigned int MULTI_STATUS;
    unsigned int ALREADY_REPORTED;
    unsigned int IM_USED;
    unsigned int MULTIPLE_CHOICES;
    unsigned int MOVED_PERMANENTLY;
    unsigned int FOUND;
    unsigned int SEE_OTHER;
    unsigned int NOT_MODIFIED;
    unsigned int USE_PROXY;
    unsigned int SWITCH_PROXY;
    unsigned int TEMPORARY_REDIRECT;
    unsigned int PERMANENT_REDIRECT;
    unsigned int BAD_REQUEST;
    unsigned int UNAUTHORIZED;
    unsigned int PAYMENT_REQUIRED;
    unsigned int FORBIDDEN;
    unsigned int NOT_FOUND;
    unsigned int NOT_ALLOWED;
    unsigned int NOT_ACCEPTABLE;
    unsigned int PROXY_AUTHENTICATION_REQUIRED;
    unsigned int REQUEST_TIMEOUT;
    unsigned int CONFLICT;
    unsigned int GONE;
    unsigned int LENGTH_REQUIRED;
    unsigned int PRECONDITION_FAILED;
    unsigned int PAYLOAD_TOO_LARGE;
    unsigned int URI_TOO_LONG;
    unsigned int UNSUPPORTED_MEDIA_TYPE;
    unsigned int RANGE_NOT_SATISFIABLE;
    unsigned int EXPECTATION_FAILED;
    unsigned int MISDIRECTED_REQUEST;
    unsigned int UNPROCESSABLE_ENTITY;
    unsigned int LOCKED;
    unsigned int FAILED_DEPENDENCY;
    unsigned int TOO_EARLY;
    unsigned int UPGRADE_REQUIRED;
    unsigned int PRECONDITION_REQUIRED;
    unsigned int TOO_MANY_REQUESTS;
    unsigned int REQUEST_HEADER_FIELDS_TOO_LARGE;
    unsigned int UNAVAILABLE_FOR_LEGAL_REASONS;
    unsigned int INTERNAL_SERVER_ERROR;
    unsigned int NOT_IMPLEMENTED;
    unsigned int BAD_GATEWAY;
    unsigned int SERVICE_UNAVAILABLE;
    unsigned int GATEWAY_TIMEOUT;
    unsigned int VERSION_NOT_SUPPORTED;
    unsigned int VARIANT_ALSO_NEGOTIATES;
    unsigned int INSUFFICIENT_STORAGE;
    unsigned int LOOP_DETECTED;
    unsigned int NOT_EXTENDED;
    unsigned int NETWORK_AUTHENTICATION_REQUIRED;

    unsigned int RETRY_WITH;
    unsigned int BLOCKED_BY_WINDOWS_PARENTAL_CONTROLS;
    unsigned int BANDWIDTH_LIMIT_EXCEEDED;

    /*unsigned int METHOD_NOT_ACCEPTABLE;
    unsigned int REQUEST_ENTITY_TOO_LARGE;
    unsigned int REQUEST_URI_TOO_LONG;
    unsigned int REQUESTED_RANGE_NOT_SATISFIABLE;
    unsigned int UNORDERED_COLLECTION;
    unsigned int NO_RESPONSE;*/
  } DGRHResponsesCodes;

  typedef struct DGRHttpHeaders {
    string ACCEPT;
    string ACCEPT_CHARSET;
    string ACCEPT_ENCODING;
    string ACCEPT_LANGUAGE;
    string ACCEPT_RANGES;
    string AGE;
    string ALLOW;
    string AUTHORIZATION;
    string CACHE_CONTROL;
    string CLOSE;
    string CONNECTION;
    string CONTENT_ENCODING;
    string CONTENT_LANGUAGE;
    string CONTENT_LENGTH;
    string CONTENT_LOCATION;
    string CONTENT_RANGE;
    string CONTENT_TYPE;
    string DATE;
    string ETAG;
    string EXPECT;
    string EXPIRES;
    string FROM;
    string HOST;
    string IF_MATCH;
    string IF_MODIFIED_SINCE;
    string IF_NONE_MATCH;
    string IF_RANGE;
    string IF_UNMODIFIED_SINCE;
    string LAST_MODIFIED;
    string LOCATION;
    string MAX_FORWARDS;
    string MIME_VERSION;
    string PRAGMA;
    string PROXY_AUTHENTICATE;
    string PROXY_AUTHORIZATION;
    string RANGE;
    string REFERER;
    string RETRY_AFTER;
    string SERVER;
    string TE;
    string TRAILER;
    string TRANSFER_ENCODING;
    string UPGRADE;
    string USER_AGENT;
    string VARY;
    string VIA;
    string WWW_AUTHENTICATE;
    string WARNING;
    string A_IM;
    string ACCEPT_ADDITIONS;
    string ACCEPT_DATETIME;
    string ACCEPT_FEATURES;
    string ACCEPT_PATCH;
    string ACCEPT_POST;
    string ALPN;
    string ALT_SVC;
    string ALT_USED;
    string ALTERNATES;
    string APPLY_TO_REDIRECT_REF;
    string AUTHENTICATION_CONTROL;
    string AUTHENTICATION_INFO;
    string C_EXT;
    string C_MAN;
    string C_OPT;
    string C_PEP;
    string C_PEP_INFO;
    string CAL_MANAGED_ID;
    string CALDAV_TIMEZONES;
    string CDN_LOOP;
    string CONTENT_BASE;
    string CONTENT_DISPOSITION;
    string CONTENT_ID;
    string CONTENT_MD5;
    string CONTENT_SCRIPT_TYPE;
    string CONTENT_STYLE_TYPE;
    string CONTENT_VERSION;
    string COOKIE;
    string COOKIE2;
    string DASL;
    string DAV;
    string DEFAULT_STYLE;
    string DELTA_BASE;
    string DEPTH;
    string DERIVED_FROM;
    string DESTINATION;
    string DIFFERENTIAL_ID;
    string DIGEST;
    string EARLY_DATA;
    string EXPECT_CT;
    string EXT;
    string FORWARDED;
    string GETPROFILE;
    string HOBAREG;
    string HTTP2_SETTINGS;
    string IM;
    string IF;
    string IF_SCHEDULE_TAG_MATCH;
    string INCLUDE_REFERRED_TOKEN_BINDING_ID;
    string KEEP_ALIVE;
    string LABEL;
    string LINK;
    string LOCK_TOKEN;
    string MAN;
    string MEMENTO_DATETIME;
    string METER;
    string NEGOTIATE;
    string OPT;
    string OPTIONAL_WWW_AUTHENTICATE;
    string ORDERING_TYPE;
    string ORIGIN;
    string OSCORE;
    string OVERWRITE;
    string P3P;
    string PEP;
    string PICS_LABEL;
    string PEP_INFO;
    string POSITION;
    string PREFER;
    string PREFERENCE_APPLIED;
    string PROFILEOBJECT;
    string PROTOCOL;
    string PROTOCOL_INFO;
    string PROTOCOL_QUERY;
    string PROTOCOL_REQUEST;
    string PROXY_AUTHENTICATION_INFO;
    string PROXY_FEATURES;
    string PROXY_INSTRUCTION;
    string PUBLIC;
    string PUBLIC_KEY_PINS;
    string PUBLIC_KEY_PINS_REPORT_ONLY;
    string REDIRECT_REF;
    string REPLAY_NONCE;
    string SAFE;
    string SCHEDULE_REPLY;
    string SCHEDULE_TAG;
    string SEC_TOKEN_BINDING;
    string SEC_WEBSOCKET_ACCEPT;
    string SEC_WEBSOCKET_EXTENSIONS;
    string SEC_WEBSOCKET_KEY;
    string SEC_WEBSOCKET_PROTOCOL;
    string SEC_WEBSOCKET_VERSION;
    string SECURITY_SCHEME;
    string SET_COOKIE;
    string SET_COOKIE2;
    string SETPROFILE;
    string SLUG;
    string SOAPACTION;
    string STATUS_URI;
    string STRICT_TRANSPORT_SECURITY;
    string SUNSET;
    string SURROGATE_CAPABILITY;
    string SURROGATE_CONTROL;
    string TCN;
    string TIMEOUT;
    string TOPIC;
    string TTL;
    string URGENCY;
    string URI;
    string VARIANT_VARY;
    string WANT_DIGEST;
    string X_FRAME_OPTIONS;
    string ACCESS_CONTROL_ALLOW_ORIGIN;
  } DGRHttpHeaders;

  typedef struct DGRHMethods {
    //string CONNECT;
    string DELETE;
    string GET;
    string HEAD;
    string OPTIONS;
    string POST;
    string PUT;
    string TRACE;
    /*string ACL;
    string BASELINE_CONTROL;
    string BIND;
    string CHECKIN;
    string CHECKOUT;
    string COPY;
    string LABEL;
    string LINK;
    string LOCK;
    string MERGE;
    string MKACTIVITY;
    string MKCALENDAR;
    string MKCOL;
    string MKREDIRECTREF;
    string MKWORKSPACE;
    string MOVE;
    string ORDERPATCH;*/
    string PATCH;
    /*string PRI;
    string PROPFIND;
    string PROPPATCH;
    string REBIND;
    string REPORT;
    string SEARCH;
    string UNBIND;
    string UNCHECKOUT;
    string UNLINK;
    string UNLOCK;
    string UPDATE;
    string UPDATEREDIRECTREF;
    string VERSION_CONTROL;*/
  } DGRHMethods;

  typedef struct DGRHMediaTypes {
    string ALL;
    string APPLICATION_ATOM_XML;
    string APPLICATION_CBOR;
    string APPLICATION_FORM_URLENCODED;
    string APPLICATION_JSON;
    string APPLICATION_JSON_UTF8;
    string APPLICATION_NDJSON;
    string APPLICATION_OCTET_STREAM;
    string APPLICATION_PDF;
    string APPLICATION_PROBLEM_JSON;
    string APPLICATION_PROBLEM_JSON_UTF8;
    string APPLICATION_PROBLEM_XML;
    string APPLICATION_RSS_XML;
    string APPLICATION_STREAM_JSON;
    string APPLICATION_XHTML_XML;
    string APPLICATION_XML;
    string APPLICATION_JAVASCRIPT;
    string IMAGE_GIF;
    string IMAGE_JPEG;
    string IMAGE_PNG;
    string MULTIPART_FORM_DATA;
    string MULTIPART_MIXED;
    string MULTIPART_RELATED;
    string TEXT_EVENT_STREAM;
    string TEXT_HTML;
    string TEXT_Markup;
    string TEXT_PLAIN;
    string TEXT_XML;
  } DGRHMediaTypes;

  typedef struct DGRHHttpPostEncodings {
    string POST_ENCODING_FORM_URLENCODED;
    string POST_ENCODING_MULTIPART_FORMDATA;
  } DGRHHttpPostEncodings;

  typedef struct DGRHNetworkTypesString {
    unsigned short IPV4;
    unsigned short IPV6;
    unsigned short ALL;
  } DGRHNetworkTypesString;

  typedef struct DGRHNetworkTypesInteger {
    unsigned short IPV4;
    unsigned short IPV6;
    unsigned short ALL;
  } DGRHNetworkTypesInteger;

  typedef struct DGRHProtocols {
    string HTTP;
    string HTTPS;
  } DGRHProtocols;

  typedef struct DGRHNetworkTypes {
    DGRHNetworkTypesString stringValues;
    DGRHNetworkTypesInteger integerValues;
  } DGRHNetworkTypes;

  typedef struct DGRHttp {
    DGRHttpHeaders (*getHeaders)();
    DGRHMethods (*getMethods)();
    DGUHashTable *(*getHTMethods)();
    DGRHResponsesCodes (*getResponsesCodes)();
    DGRHMediaTypes (*getMediaTypes)();
    DGRHNetworkTypes (*getNetworkTypes)();
    DGRHProtocols (*getProtocols)();
    bool (*isMethodPOSTRaw)(string method, string contentType);
    bool (*isMethodPOSTFile)(string method, string contentType);
    bool (*isMethodPOSTMultipart)(string method, string contentType);
    bool (*isMethodGET)(string method);
  } DGRHttp;

#ifdef __cplusplus
}
#endif

#endif //DGR_HTTP_GLOBAL_H
