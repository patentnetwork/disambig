/*-
 * See the file LICENSE for redistribution information.
 *
 * Copyright (c) 2005,2008 Oracle.  All rights reserved.
 *
 * $Id: sqlite_db_extern.h,v 1.10 2008/01/08 20:58:23 bostic Exp $
 */

extern DbRecord DbRecord_base;			/* Initialized structure. */
extern DbField fieldlist[];
extern char* sql_query;

/*
 * Prototypes
 */
extern int	DbRecord_discard(DbRecord *);
extern int  DbRecord_dump(DbRecord *);
extern int	DbRecord_init(const DBT *, const DBT *, DbRecord *);
extern void	DbRecord_print(DbRecord *, FILE *);
extern int	DbRecord_read(u_long, DbRecord *);
extern int	DbRecord_search_field_name(char *, char *, OPERATOR);
extern int	DbRecord_search_field_number(u_int, char *, OPERATOR);
extern int	compare_double(DB *, const DBT *, const DBT *);
extern int	compare_string(DB *, const DBT *, const DBT *);
extern int	compare_ulong(DB *, const DBT *, const DBT *);
extern int  compare_uint32(DB *, const DBT *, const DBT *);
extern int	sqlite_db_env_close(void);
extern int	sqlite_db_env_open(const char *);
extern int  sqlite_db_primary_open(DB **, const char*, DBTYPE, u_int32_t, u_int32_t, u_int32_t,
                                    int(*)(DB*, const DBT*, const DBT*));
extern int  sqlite_db_oldenv_open(DB **, const char *, int);
extern int	sqlite_db_secondary_close(void);
extern int  sqlite_db_secondary_open(DB*, DB **, char*, u_int32_t, u_int32_t, int(*)(DB*, const DBT*, const DBT*, DBT*),
                                    int(*)(DB*, const DBT*, const DBT*));
//extern int	sqlite_db_secondary_open(void);
extern int	entry_print(void *, size_t, u_int32_t);
extern int	field_cmp_double(void *, void *, OPERATOR);
extern int	field_cmp_re(void *, void *, OPERATOR);
extern int	field_cmp_string(void *, void *, OPERATOR);
extern int	field_cmp_ulong(void *, void *, OPERATOR);
extern int	input_load(DB *, sqlite3 *, char *);
extern int	query(char *, int *);
extern int	query_interactive(void);
extern int	secondary_callback(DB *, const DBT *, const DBT *, DBT *);
extern int	strtod_err(char *, double *);
extern int	strtoul_err(char *, u_long *);

/*
 * Blocking Specific
 */

extern datatype block_type;
extern int sqlite_db_blockidx_open(DB**);
extern int blocking_callback(DB*, const DBT*, const DBT*, DBT*);

/*
 * Index Specific
 */

extern int index_callback(DB*, const DBT*, const DBT*, DBT*);

