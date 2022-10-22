/ *
	SA-MP MySQL plugin R5
	Copyright (c) 2008-2010, G-sTyLeZzZ 
* /

# Definido mysql_incluído
	#endinput
#fim se
#define  mysql_included

// Códigos de erro comuns (http://dev.mysql.com/doc/refman/5.0/en/error-messages-(client|server).html)

#define  ER_DBACCESS_DENIED_ERROR  1044
#define  ER_ACCESS_DENIED_ERROR  1045
#define  ER_UNKNOWN_TABLE  1109
#define  ER_SYNTAX_ERROR  1149
#define  CR_SERVER_GONE_ERROR  2006
#define  CR_SERVER_LOST  2013
#define  CR_COMMAND_OUT_OF_SYNC  2014
#define  CR_SERVER_LOST_EXTENDED  2055

// Funções nativas

#define  mysql_fetch_row (% 1 )  mysql_fetch_row_format (% 1 , "|" )
#define  mysql_next_row ()  mysql_retrieve_row ()
#define  mysql_get_field (% 1 ,% 2 )  mysql_fetch_field_row (% 2 ,% 1 )

mysql_affected_rows nativo ( connectionHandle =  1 );
mysql_close nativo ( connectionHandle =  1 );
mysql_connect nativo ( const host [], const user [], const database [], const password []);
mysql_debug nativo ( enable =  1 );
mysql_errno nativo ( connectionHandle =  1 );
mysql_fetch_int nativo ( connectionHandle =  1 );
mysql_fetch_field nativo ( número , dest [], connectionHandle =  1 );
mysql_fetch_field_row nativo ( string [], const namename [], connectionHandle =  1 );
mysql_fetch_float nativo (& Float : result , connectionHandle =  1 );
mysql_fetch_row_format nativo ( string [], const delimiter []  =  "|" , connectionHandle =  1 );
mysql_format nativo ( connectionHandle , output [], format [],  { Float , _ }: ...);
mysql_field_count nativo ( connectionHandle =  1 );
mysql_free_result nativo ( connectionHandle =  1 );
mysql_get_charset nativo ( destino [], connectionHandle =  1 );
mysql_insert_id nativo ( connectionHandle =  1 );
mysql_num_rows nativo ( connectionHandle =  1 );
mysql_num_fields nativos ( connectionHandle =  1 );
mysql_ping nativo ( connectionHandle =  1 );
mysql_query nativo ( query [], resulttid =  (- 1 ), extraid =  (- 1 ), connectionHandle =  1 );
mysql_query_callback nativo ( index , query [], callback [], extraid =  (- 1 ), connectionHandle =  1 );
mysql_real_escape_string nativo ( fonte const [], destino [], connectionHandle =  1 );
mysql_reconnect nativo ( connectionHandle =  1 );
mysql_reload nativo ( connectionHandle =  1 );
mysql_retrieve_row nativo ( connectionHandle =  1 );
mysql_set_charset nativo ( charset [], connectionHandle =  1 );
mysql_stat nativo ( destino const [], connectionHandle =  1 );
mysql_store_result nativo ( connectionHandle =  1 );
mysql_warning_count nativo ( connectionHandle =  1 );

// declarações para a frente

encaminhar OnQueryFinish ( consulta [], resulttid , extraid , connectionHandle );
encaminhar OnQueryError ( errorid , error [], resulttid , extraid , callback [], query [], connectionHandle );