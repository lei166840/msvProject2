#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int $$state_num=0;
int $$pathNum=1;
int $$len_i=0;
int $$flag[100] = { 0 };
int $$length = 0, $$current = 0,$$firstTime=0;
void $$changeState()
{if ($$current == $$length){
$$length++; $$flag[$$length - 1] = 0;}
$$current++; }
struct __anonunion___value_2{
int __wch;
char __wchb[4];
}
;
struct __anonstruct__mbstate_t_1{
int __count;
struct __anonunion___value_2 *__value;
}
;
struct _Bigint{
struct _Bigint *_next;
int _k;
int _maxwds;
int _sign;
int _wds;
int _x[1];
}
;
struct __tm{
int __tm_sec;
int __tm_min;
int __tm_hour;
int __tm_mday;
int __tm_mon;
int __tm_year;
int __tm_wday;
int __tm_yday;
int __tm_isdst;
}
;
struct _on_exit_args{
void *_fnargs[32];
void *_dso_handle[32];
int _fntypes;
int _is_cxa;
}
;
struct _atexit{
struct _atexit *_next;
int _ind;
struct _on_exit_args *_on_exit_args$;
}
;
struct __sbuf{
unsigned char *_base;
int _size;
}
;
struct __sFILE64{
unsigned char *_p;
int _r;
int _w;
int _flags;
int _file;
struct __sbuf *_bf;
int _lbfsize;
struct _reent *_data;
void *_cookie;
struct __sbuf *_ub;
unsigned char *_up;
int _ur;
unsigned char _ubuf[3];
unsigned char _nbuf[1];
struct __sbuf *_lb;
int _blksize;
int _flags2;
int _offset;
void *_lock;
}
;
struct _glue{
struct _glue *_next;
int _niobs;
struct __sFILE64 *_iobs;
}
;
struct _rand48{
int _seed[3];
int _mult[3];
int _add;
}
;
struct __anonstruct__reent_4{
int _unused_rand;
char *_strtok_last;
char _asctime_buf[26];
struct __tm *_localtime_buf;
int _gamma_signgam;
int _rand_next;
struct _rand48 *_r48;
struct __anonstruct__mbstate_t_1 _mblen_state;
struct __anonstruct__mbstate_t_1 _mbtowc_state;
struct __anonstruct__mbstate_t_1 _wctomb_state;
char _l64a_buf[8];
char _signal_buf[24];
int _getdate_err;
struct __anonstruct__mbstate_t_1 _mbrlen_state;
struct __anonstruct__mbstate_t_1 _mbrtowc_state;
struct __anonstruct__mbstate_t_1 _mbsrtowcs_state;
struct __anonstruct__mbstate_t_1 _wcrtomb_state;
struct __anonstruct__mbstate_t_1 _wcsrtombs_state;
}
;
struct __anonstruct__unused_5{
unsigned char *_nextf[30];
int _nmalloc[30];
}
;
struct __anonunion__new_3{
struct __anonstruct__reent_4 *_reent$;
struct __anonstruct__unused_5 *_unused;
}
;
struct _reent{
int _errno;
struct __sFILE64 *_stdin;
struct __sFILE64 *_stdout;
struct __sFILE64 *_stderr;
int _inc;
char _emergency[25];
int _current_category;
char *_current_locale;
int __sdidinit;
struct _Bigint *_result;
int _result_k;
struct _Bigint *_p5s;
struct _Bigint *_freelist;
int _cvtlen;
char *_cvtbuf;
struct __anonunion__new_3 *_new;
struct _atexit *_atexit$;
struct _atexit *_atexit0;
struct _glue *__sglue;
struct __sFILE64 __sf[3];
}
;
struct timeval{
int tv_sec;
int tv_usec;
}
;
struct rusage{
struct timeval *ru_utime;
struct timeval *ru_stime;
int ru_maxrss;
int ru_ixrss;
int ru_idrss;
int ru_isrss;
int ru_minflt;
int ru_majflt;
int ru_nswap;
int ru_inblock;
int ru_oublock;
int ru_msgsnd;
int ru_msgrcv;
int ru_nsignals;
int ru_nvcsw;
int ru_nivcsw;
}
;
struct Symbol{
char *name;
struct Symbol *next$;
}
;
struct Node{
int ntyp;
struct Symbol *sym;
struct Node *lft;
struct Node *rgt;
struct Node *nxt;
}
;
struct Graph{
struct Symbol *name;
struct Symbol *incoming;
struct Symbol *outgoing;
struct Symbol *oldstring;
struct Symbol *nxtstring;
struct Node *New;
struct Node *Old;
struct Node *Other;
struct Node *Next;
unsigned char isred[64],isgrn[64];
unsigned char redcnt,grncnt;
unsigned char reachable;
struct Graph *nxt;
}
;
struct Mapping{
char *from;
struct Graph *to;
struct Mapping *nxt;
}
;
struct ATrans{
int *to;
int *pos;
int *neg;
struct ATrans *nxt;
}
;
struct AProd{
int astate;
struct ATrans *prod;
struct ATrans *trans;
struct AProd *nxt;
struct AProd *prv;
}
;
struct GTrans{
int *pos;
int *neg;
struct GState *to;
int *final;
struct GTrans *nxt;
}
;
struct GState{
int id;
int incoming;
int *nodes_set;
struct GTrans *trans;
struct GState *nxt;
struct GState *prv;
}
;
struct BTrans{
struct BState *to;
int *pos;
int *neg;
struct BTrans *nxt;
}
;
struct BState{
struct GState *gstate;
int id;
int incoming;
int final;
struct BTrans *trans;
struct BState *nxt;
struct BState *prv;
}
;
struct GScc{
struct GState *gstate;
int rank;
int theta;
struct GScc *nxt;
}
;
struct BScc{
struct BState *bstate;
int rank;
int theta;
struct BScc *nxt;
}
;
struct Cache{
struct Node *before;
struct Node *after;
int same;
struct Cache *nxt;
}
;
struct M{
int size;
struct M *link;
}
;
int ALWAYS;
int AND_1;
int EQUIV;
int EVENTUALLY;
int FALSE;
int IMPLIES;
int NOT;
int OR_1;
int PREDICATE;
int TRUE;
int U_OPER;
int V_OPER;
int tl_stats;
int tl_simp_log;
int tl_simp_diff;
int tl_simp_fly;
int tl_simp_scc;
int tl_fjtofj;
int tl_errs;
int tl_verbose;
int tl_terse;
int All_Mem;
char *uform;
int hasuform,cnt;
char **ltl_file;
char **add_ltl;
char out1[64];
struct Node **label;
char **sym_table;
struct ATrans **transition;
int *final_set,node_id,sym_id,node_size,sym_size;
int astate_count,atrans_count;
struct BState *bstack,*bstates,*bremoved;
struct BScc *Bscc_stack;
int accept,bstate_count,btrans_count;
struct Cache *stored;
int Caches,CacheHits;
struct GState *gstack,*gremoved,*gstates,**init;
struct GScc *scc_stack;
int init_size,gstate_id,gstate_count,gtrans_count;
int *fin$,*final,rank,scc_id,scc_size,*bad_scc;
struct Symbol *symtab[(255)+(1)];
char yytext[2048];
struct ATrans *atrans_list;
struct GTrans *gtrans_list;
struct BTrans *btrans_list;
int aallocs,afrees,apool;
int gallocs,gfrees,gpool;
int ballocs,bfrees,bpool;
struct M *freelist[80];
int req[80];
int event[3][80];
int tl_yychar;
struct Node *tl_yylval;
int prec[2][4]={{267,268,0,0},{264,258,262,259}};
struct Node *can;
int mod;
int Stack_mx,Max_Red,Total;
char dumpbuf[2048];
void  alldone(int $$Ext,int estatus);
char * emalloc(int $$Ext,int n);
int  tl_Getchar(int $$Ext);
void  put_uform(int $$Ext);
void  tl_UnGetchar(int $$Ext);
void  usage(int $$Ext);
int  tl_main_1(int $$Ext);
int  main_1(int $$Ext);
void  tl_endstats(int $$Ext);
void  dump(int $$Ext,Node* n);
void  tl_explain(int $$Ext,int n);
void  non_fatal(int $$Ext,char *s1,char *s2);
void  tl_yyerror(int $$Ext,char *s1);
void  Fatal(int $$Ext,char *s1,char *s2);
void  fatal(int $$Ext,char *s1,char *s2);
int  calculate_node_size(int $$Ext,Node* p);
int  calculate_sym_size(int $$Ext,Node* p);
ATrans*  dup_trans(int $$Ext,ATrans* trans);
void  do_merge_trans(int $$Ext,ATrans** result,ATrans* trans1,ATrans* trans2);
ATrans*  merge_trans(int $$Ext,ATrans* trans1,ATrans* trans2);
int  already_done(int $$Ext,Node* p);
int  get_sym_id(int $$Ext,char *s);
ATrans*  boolean(int $$Ext,Node* p);
ATrans*  build_alternating(int $$Ext,Node* p);
void  simplify_atrans(int $$Ext,ATrans** trans);
void  simplify_astates(int $$Ext);
void  print_alternating(int $$Ext);
void  mk_alternating(int $$Ext,Node* p);
void  free_bstate(int $$Ext,BState* s);
BState*  remove_bstate(int $$Ext,BState* s,BState* s1);
void  copy_btrans(int $$Ext,BTrans* from,BTrans* to);
int  simplify_btrans(int $$Ext);
int  same_btrans(int $$Ext,BTrans* s,BTrans* t);
void  remove_btrans(int $$Ext,BState* to);
void  retarget_all_btrans(int $$Ext);
int  all_btrans_match(int $$Ext,BState* a,BState* b);
int  simplify_bstates(int $$Ext);
int  bdfs(int $$Ext,BState* s);
void  simplify_bscc(int $$Ext);
BState*  find_bstate(int $$Ext,GState** state,int final,BState* s);
int  next_final(int $$Ext,int *set,int fin$);
void  make_btrans(int $$Ext,BState* s);
void  print_buchi(int $$Ext,BState* s);
void  print_spin_buchi(int $$Ext);
void  mk_buchi(int $$Ext);
void  cache_dump(int $$Ext);
Node*  in_cache(int $$Ext,Node* n);
Node*  cached(int $$Ext,Node* n);
void  cache_stats(int $$Ext);
void  releasenode(int $$Ext,int all_levels,Node* n);
Node*  tl_nn(int $$Ext,int t,Node* ll,Node* rl);
Node*  getnode(int $$Ext,Node* p);
Node*  dupnode(int $$Ext,Node* n);
int  one_lft(int $$Ext,int ntyp,Node* x,Node* in);
int  all_lfts(int $$Ext,int ntyp,Node* from,Node* in);
int  sametrees(int $$Ext,int ntyp,Node* a,Node* b);
int  sameform(int $$Ext,Node* a,Node* b);
int  isequal(int $$Ext,Node* a,Node* b);
int  ismatch(int $$Ext,Node* a,Node* b);
int  any_term(int $$Ext,Node* srch,Node* in);
int  any_and(int $$Ext,Node* srch,Node* in);
int  any_lor(int $$Ext,Node* srch,Node* in);
int  anywhere(int $$Ext,int tok,Node* srch,Node* in);
void  free_gstate(int $$Ext,GState* s);
GState*  remove_gstate(int $$Ext,GState* s,GState* s1);
void  copy_gtrans(int $$Ext,GTrans* from,GTrans* to);
int  same_gtrans(int $$Ext,GState* a,GTrans* s,GState* b,GTrans* t,int use_scc);
int  simplify_gtrans(int $$Ext);
void  retarget_all_gtrans(int $$Ext);
int  all_gtrans_match(int $$Ext,GState* a,GState* b,int use_scc);
int  simplify_gstates(int $$Ext);
int  gdfs(int $$Ext,GState* s);
void  simplify_gscc(int $$Ext);
int  is_final(int $$Ext,int *from,ATrans* at,int i);
GState*  find_gstate(int $$Ext,int *set,GState* s);
void  make_gtrans(int $$Ext,GState* s);
void  reverse_print_generalized(int $$Ext,GState* s);
void  print_generalized(int $$Ext);
void  mk_generalized(int $$Ext);
int  isalnum_(int $$Ext,int c);
int  hash(int $$Ext,char *s);
void  getword(int $$Ext,int first,int (*tst)(int $$Ext,int $$NoCare));
int  follow(int $$Ext,int tok,int ifyes,int ifno);
int  tl_yylex(int $$Ext);
int  tl_lex(int $$Ext);
Symbol*  tl_lookup(int $$Ext,char *s);
Symbol*  getsym(int $$Ext,Symbol* s);
void * tl_emalloc(int $$Ext,int U);
void  tfree(int $$Ext,void *v);
ATrans*  emalloc_atrans(int $$Ext);
void  free_atrans(int $$Ext,ATrans* t,int rec);
void  free_all_atrans(int $$Ext);
GTrans*  emalloc_gtrans(int $$Ext);
void  free_gtrans(int $$Ext,GTrans* t,GTrans* sentinel,int fly);
BTrans*  emalloc_btrans(int $$Ext);
void  free_btrans(int $$Ext,BTrans* t,BTrans* sentinel,int fly);
void  a_stats(int $$Ext);
int  implies(int $$Ext,Node* a,Node* b);
Node*  bin_simpler(int $$Ext,Node* ptr);
Node*  bin_minimal(int $$Ext,Node* ptr);
Node*  tl_factor(int $$Ext);
Node*  tl_level(int $$Ext,int nr);
Node*  tl_formula(int $$Ext);
void  tl_parse(int $$Ext);
Node*  right_linked(int $$Ext,Node* n);
Node*  canonical(int $$Ext,Node* n);
Node*  push_negation(int $$Ext,Node* n);
void  addcan(int $$Ext,int tok,Node* n);
void  marknode(int $$Ext,int tok,Node* m);
Node*  Canonical(int $$Ext,Node* n);
int * new_set(int $$Ext,int type);
int * clear_set(int $$Ext,int *l,int type);
int * make_set(int $$Ext,int n,int type);
void  copy_set(int $$Ext,int *from,int *to,int type);
int * dup_set(int $$Ext,int *l,int type);
void  merge_sets(int $$Ext,int *l1,int *l2,int type);
void  do_merge_sets(int $$Ext,int *l,int *l1,int *l2,int type);
int * intersect_sets(int $$Ext,int *l1,int *l2,int type);
int  empty_intersect_sets(int $$Ext,int *l1,int *l2,int type);
void  add_set(int $$Ext,int *l,int n);
void  rem_set(int $$Ext,int *l,int n);
void  spin_print_set(int $$Ext,int *pos,int *neg);
void  print_set(int $$Ext,int *l,int type);
int  empty_set(int $$Ext,int *l,int type);
int  same_sets(int $$Ext,int *l1,int *l2,int type);
int  included_set(int $$Ext,int *l1,int *l2,int type);
int  in_set(int $$Ext,int *l,int n);
int * list_set(int $$Ext,int *l,int type);
int  dump_cond(int $$Ext,Node* pp,Node* r,int first);
void  sdump(int $$Ext,Node* n);
Symbol*  DoDump(int $$Ext,Node* n);
void  trans(int $$Ext,Node* p);
void  alldone(int $$Ext,int estatus){
if (strlen(out1)>0){;
}
;
}
char * emalloc(int $$Ext,int n){
char * RValue=0;
int return_1;
char *emalloc_tmp;
return_1=0;
emalloc_tmp=(char *)(malloc(n));
if (!emalloc_tmp){fatal(0,"not enough memory",NULL);
}
;
memset(emalloc_tmp,0,n);
return_1=1;
RValue=emalloc_tmp;
return RValue;
}
int  tl_Getchar(int $$Ext){
int  RValue=0;
int return_1;
return_1=0;
if (cnt<hasuform){return_1=1;
RValue=uform[cnt];
cnt=(cnt)+(1);
}
;
if (return_1==0){cnt=(cnt)+(1);
return_1=1;
RValue=-1;
}
;
return RValue;
}
void  put_uform(int $$Ext){
printf("%p",uform);
}
void  tl_UnGetchar(int $$Ext){
if (cnt>0){cnt=(cnt)-(1);
}
;
}
void  usage(int $$Ext){
printf("usage: ltl2ba [-flag] -f formula\n");
printf("                   or -F file\n");
printf(" -f \"formula\"\ttranslate LTL ");
printf("into never claim\n");
printf(" -F file\tlike -f, but with the LTL ");
printf("formula stored in a 1-line file\n");
printf(" -d\t\tdisplay automata (D)escription at each step\n");
printf(" -s\t\tcomputing time and automata sizes (S)tatistics\n");
printf(" -l\t\tdisable (L)ogic formula simplification\n");
printf(" -p\t\tdisable a-(P)osteriori simplification\n");
printf(" -o\t\tdisable (O)n-the-fly simplification\n");
printf(" -c\t\tdisable strongly (C)onnected components simplification\n");
printf(" -a\t\tdisable trick in (A)ccepting conditions\n");
alldone(0,1);
}
int  tl_main_1(int $$Ext){
int  RValue=0;
int return_1;
int tl_main_1_i;
return_1=0;
uform="(((((((p1 U p2) U p3) U p4) U p5) U p6) U p7) U p8) U p9";
hasuform=strlen(uform);
if (hasuform==0){usage(0);
}
;
tl_parse(0);
if (tl_stats){tl_endstats(0);
}
;
return_1=1;
RValue=tl_errs;
return RValue;
}
int  main_1(int $$Ext){
int  RValue=0;
int return_1;
int main_1_i;
char main_1_1_formula[4096];
return_1=0;
if (ltl_file){add_ltl=(ltl_file)-(2);
add_ltl[1][1]='f';
(*(ltl_file))=(char *)(main_1_1_formula);
}
;
tl_main_1(0);
return_1=1;
RValue=0;
return RValue;
}
void  tl_endstats(int $$Ext){
printf("\ntotal memory used: ");
printf("%d",All_Mem);
printf("\n");
a_stats(0);
}
void  dump(int $$Ext,Node* n){
int return_1;
int switch_1;
int break_1$;
int nm_1$;
return_1=0;
if (!n){return_1=1;
}
;
if (return_1==0){break_1$=0;
switch_1=0;
nm_1$=n->ntyp;
if ((nm_1$==OR_1) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
printf("(");
dump(0,n->lft);
printf(" || ");
dump(0,n->rgt);
printf(")");
break_1$=1;
}
;
if ((nm_1$==AND_1) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
printf("(");
dump(0,n->lft);
printf(" && ");
dump(0,n->rgt);
printf(")");
break_1$=1;
}
;
if ((nm_1$==U_OPER) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
printf("(");
dump(0,n->lft);
printf(" U ");
dump(0,n->rgt);
printf(")");
break_1$=1;
}
;
if ((nm_1$==V_OPER) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
printf("(");
dump(0,n->lft);
printf(" V ");
dump(0,n->rgt);
printf(")");
break_1$=1;
}
;
if ((nm_1$==NOT) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
printf("!");
printf(" (");
dump(0,n->lft);
printf(")");
break_1$=1;
}
;
if ((nm_1$==FALSE) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
printf("false");
break_1$=1;
}
;
if ((nm_1$==TRUE) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
printf("true");
break_1$=1;
}
;
if ((nm_1$==PREDICATE) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
printf("(");
;
printf(")");
break_1$=1;
}
;
if ((nm_1$==-1) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
printf(" D ");
break_1$=1;
}
;
if ((break_1$==0) && (return_1==0)){printf("Unknown token: ");
tl_explain(0,n->ntyp);
break_1$=1;
}
;
}
;
}
void  tl_explain(int $$Ext,int n){
int return_1;
int switch_1;
int break_1$;
int nm_2$;
return_1=0;
break_1$=0;
switch_1=0;
nm_2$=n;
if ((nm_2$==ALWAYS) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
printf("[]");
break_1$=1;
}
;
if ((nm_2$==EVENTUALLY) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
printf("<>");
break_1$=1;
}
;
if ((nm_2$==IMPLIES) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
printf("->");
break_1$=1;
}
;
if ((nm_2$==EQUIV) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
printf("<->");
break_1$=1;
}
;
if ((nm_2$==PREDICATE) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
printf("predicate");
break_1$=1;
}
;
if ((nm_2$==OR_1) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
printf("||");
break_1$=1;
}
;
if ((nm_2$==AND_1) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
printf("&&");
break_1$=1;
}
;
if ((nm_2$==NOT) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
printf("!");
break_1$=1;
}
;
if ((nm_2$==U_OPER) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
printf("U");
break_1$=1;
}
;
if ((nm_2$==V_OPER) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
printf("V");
break_1$=1;
}
;
if ((nm_2$==TRUE) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
printf("true");
break_1$=1;
}
;
if ((nm_2$==FALSE) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
printf("false");
break_1$=1;
}
;
if ((nm_2$==';') || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
printf("end of formula");
break_1$=1;
}
;
if ((break_1$==0) && (return_1==0)){printf("%d",n);
break_1$=1;
}
;
}
void  non_fatal(int $$Ext,char *s1,char *s2){
int non_fatal_i;
printf("ltl2ba: ");
if (s2){printf("%p",s1);
printf("%p",s2);
} else {printf("%p",s1);
}
;
if (((tl_yychar)!=(-1)) && ((tl_yychar)!=(0))){printf(", saw \'");
tl_explain(0,tl_yychar);
printf("\'");
}
;
printf("\nltl2ba: ");
printf("%p",uform);
printf("\n---------");
non_fatal_i=0;
while(non_fatal_i<cnt){printf("-");
non_fatal_i=(non_fatal_i)+(1);
}
;
printf("^\n");
tl_errs=(tl_errs)+(1);
}
void  tl_yyerror(int $$Ext,char *s1){
Fatal(0,s1,NULL);
}
void  Fatal(int $$Ext,char *s1,char *s2){
non_fatal(0,s1,s2);
alldone(0,1);
}
void  fatal(int $$Ext,char *s1,char *s2){
non_fatal(0,s1,s2);
alldone(0,1);
}
int  calculate_node_size(int $$Ext,Node* p){
int  RValue=0;
int return_1;
int switch_1;
int break_1$;
int nm_3$;
return_1=0;
break_1$=0;
switch_1=0;
nm_3$=p->ntyp;
if ((nm_3$==AND_1) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
}
;
if ((nm_3$==OR_1) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
}
;
if ((nm_3$==U_OPER) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
}
;
if ((nm_3$==V_OPER) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
return_1=1;
RValue=((calculate_node_size(1,p->lft))+(calculate_node_size(1,p->rgt)))+(1);
}
;
if ((break_1$==0) && (return_1==0)){return_1=1;
RValue=1;
break_1$=1;
}
;
return RValue;
}
int  calculate_sym_size(int $$Ext,Node* p){
int  RValue=0;
int return_1;
int switch_1;
int break_1$;
int nm_4$;
return_1=0;
break_1$=0;
switch_1=0;
nm_4$=p->ntyp;
if ((nm_4$==AND_1) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
}
;
if ((nm_4$==OR_1) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
}
;
if ((nm_4$==U_OPER) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
}
;
if ((nm_4$==V_OPER) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
return_1=1;
RValue=(calculate_sym_size(1,p->lft))+(calculate_sym_size(1,p->rgt));
}
;
if ((nm_4$==NOT) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
}
;
if ((nm_4$==PREDICATE) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
return_1=1;
RValue=1;
}
;
if ((break_1$==0) && (return_1==0)){return_1=1;
RValue=0;
}
;
return RValue;
}
ATrans*  dup_trans(int $$Ext,ATrans* trans){
ATrans*  RValue=0;
int return_1;
struct ATrans *dup_trans_result;
return_1=0;
if (!trans){return_1=1;
RValue=trans;
}
;
if (return_1==0){dup_trans_result=emalloc_atrans(0);
copy_set(0,trans->to,dup_trans_result->to,0);
copy_set(0,trans->pos,dup_trans_result->pos,1);
copy_set(0,trans->neg,dup_trans_result->neg,1);
return_1=1;
RValue=dup_trans_result;
}
;
return RValue;
}
void  do_merge_trans(int $$Ext,ATrans** result,ATrans* trans1,ATrans* trans2){
int return_1;
return_1=0;
if ((!trans1) || (!trans2)){free_atrans(0,(*(result)),0);
(*(result))=NULL;
return_1=1;
}
;
if (return_1==0){if (!((*(result)))){(*(result))=emalloc_atrans(0);
}
;
do_merge_sets(0,(*(result))->to,trans1->to,trans2->to,0);
do_merge_sets(0,(*(result))->pos,trans1->pos,trans2->pos,1);
do_merge_sets(0,(*(result))->neg,trans1->neg,trans2->neg,1);
if (!(empty_intersect_sets(1,(*(result))->pos,(*(result))->neg,1))){free_atrans(0,(*(result)),0);
(*(result))=NULL;
}
;
}
;
}
ATrans*  merge_trans(int $$Ext,ATrans* trans1,ATrans* trans2){
ATrans*  RValue=0;
int return_1;
struct ATrans *merge_trans_result;
return_1=0;
merge_trans_result=emalloc_atrans(0);
do_merge_trans(0,&merge_trans_result,trans1,trans2);
return_1=1;
RValue=merge_trans_result;
return RValue;
}
int  already_done(int $$Ext,Node* p){
int  RValue=0;
int return_1;
int already_done_i;
return_1=0;
already_done_i=1;
while((return_1==0) && (already_done_i<node_id)){if (isequal(1,p,label[already_done_i])){return_1=1;
RValue=already_done_i;
}
;
if (return_1==0){already_done_i=(already_done_i)+(1);
}
;
}
;
if (return_1==0){return_1=1;
RValue=-1;
}
;
return RValue;
}
int  get_sym_id(int $$Ext,char *s){
int  RValue=0;
int return_1;
int get_sym_id_i;
return_1=0;
get_sym_id_i=0;
while((return_1==0) && (get_sym_id_i<sym_id)){if (!(strcmp(s,sym_table[get_sym_id_i]))){return_1=1;
RValue=get_sym_id_i;
}
;
if (return_1==0){get_sym_id_i=(get_sym_id_i)+(1);
}
;
}
;
if (return_1==0){sym_table[sym_id]=s;
return_1=1;
RValue=sym_id;
sym_id=(sym_id)+(1);
}
;
return RValue;
}
ATrans*  boolean(int $$Ext,Node* p){
ATrans*  RValue=0;
int return_1;
struct ATrans *boolean_t1,*boolean_t2,*boolean_lft,*boolean_rgt,*boolean_result;
int boolean_id;
int switch_1;
int break_1$;
int nm_5$;
struct ATrans *boolean_1_tmp;
struct ATrans *boolean_1_tmp_1;
struct ATrans *boolean_1_tmp_2;
int boolean_1_temp$_1;
return_1=0;
boolean_result=NULL;
break_1$=0;
switch_1=0;
nm_5$=p->ntyp;
if ((nm_5$==TRUE) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
boolean_result=emalloc_atrans(0);
clear_set(0,boolean_result->to,0);
clear_set(0,boolean_result->pos,1);
clear_set(0,boolean_result->neg,1);
}
;
if ((nm_5$==FALSE) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
break_1$=1;
}
;
if ((nm_5$==AND_1) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
boolean_lft=boolean(0,p->lft);
boolean_rgt=boolean(0,p->rgt);
boolean_t1=boolean_lft;
while(boolean_t1){boolean_t2=boolean_rgt;
while(boolean_t2){boolean_1_tmp=merge_trans(0,boolean_t1,boolean_t2);
if (boolean_1_tmp){boolean_1_tmp->nxt=boolean_result;
boolean_result=boolean_1_tmp;
}
;
boolean_t2=boolean_t2->nxt;
}
;
boolean_t1=boolean_t1->nxt;
}
;
free_atrans(0,boolean_lft,1);
free_atrans(0,boolean_rgt,1);
break_1$=1;
}
;
if ((nm_5$==OR_1) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
boolean_lft=boolean(0,p->lft);
boolean_t1=boolean_lft;
while(boolean_t1){boolean_1_tmp_1=dup_trans(0,boolean_t1);
boolean_1_tmp_1->nxt=boolean_result;
boolean_result=boolean_1_tmp_1;
boolean_t1=boolean_t1->nxt;
}
;
free_atrans(0,boolean_lft,1);
boolean_rgt=boolean(0,p->rgt);
boolean_t1=boolean_rgt;
while(boolean_t1){boolean_1_tmp_2=dup_trans(0,boolean_t1);
boolean_1_tmp_2->nxt=boolean_result;
boolean_result=boolean_1_tmp_2;
boolean_t1=boolean_t1->nxt;
}
;
free_atrans(0,boolean_rgt,1);
break_1$=1;
}
;
if ((break_1$==0) && (return_1==0)){build_alternating(0,p);
boolean_result=emalloc_atrans(0);
clear_set(0,boolean_result->to,0);
clear_set(0,boolean_result->pos,1);
clear_set(0,boolean_result->neg,1);
boolean_1_temp$_1=already_done(0,p);
add_set(0,boolean_result->to,boolean_1_temp$_1);
}
;
return_1=1;
RValue=boolean_result;
return RValue;
}
ATrans*  build_alternating(int $$Ext,Node* p){
ATrans*  RValue=0;
int return_1;
struct ATrans *build_alternating_t1,*build_alternating_t2,*build_alternating_t;
int build_alternating_node;
int switch_1;
int break_1$;
int nm_6$;
int build_alternating_2_temp$_1;
int build_alternating_2_temp$_2;
struct ATrans *build_alternating_2_tmp;
struct ATrans *build_alternating_2_tmp_2;
struct ATrans *build_alternating_2_tmp_3;
struct ATrans *build_alternating_2_tmp_4;
struct ATrans *build_alternating_2_tmp_5;
struct ATrans *build_alternating_2_tmp_6;
return_1=0;
build_alternating_t=NULL;
build_alternating_node=already_done(0,p);
if (build_alternating_node>=0){return_1=1;
RValue=transition[build_alternating_node];
}
;
if (return_1==0){break_1$=0;
switch_1=0;
nm_6$=p->ntyp;
if ((nm_6$==TRUE) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
build_alternating_t=emalloc_atrans(0);
clear_set(0,build_alternating_t->to,0);
clear_set(0,build_alternating_t->pos,1);
clear_set(0,build_alternating_t->neg,1);
}
;
if ((nm_6$==FALSE) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
break_1$=1;
}
;
if ((nm_6$==PREDICATE) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
build_alternating_t=emalloc_atrans(0);
clear_set(0,build_alternating_t->to,0);
clear_set(0,build_alternating_t->pos,1);
clear_set(0,build_alternating_t->neg,1);
build_alternating_2_temp$_1=get_sym_id(0,p->sym->name);
add_set(0,build_alternating_t->pos,build_alternating_2_temp$_1);
break_1$=1;
}
;
if ((nm_6$==NOT) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
build_alternating_t=emalloc_atrans(0);
clear_set(0,build_alternating_t->to,0);
clear_set(0,build_alternating_t->pos,1);
clear_set(0,build_alternating_t->neg,1);
build_alternating_2_temp$_2=get_sym_id(0,p->lft->sym->name);
add_set(0,build_alternating_t->neg,build_alternating_2_temp$_2);
break_1$=1;
}
;
if ((nm_6$==U_OPER) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
build_alternating_t2=build_alternating(0,p->rgt);
while(build_alternating_t2){build_alternating_2_tmp=dup_trans(0,build_alternating_t2);
build_alternating_2_tmp->nxt=build_alternating_t;
build_alternating_t=build_alternating_2_tmp;
build_alternating_t2=build_alternating_t2->nxt;
}
;
build_alternating_t1=build_alternating(0,p->lft);
while(build_alternating_t1){build_alternating_2_tmp_2=dup_trans(0,build_alternating_t1);
add_set(0,build_alternating_2_tmp_2->to,node_id);
build_alternating_2_tmp_2->nxt=build_alternating_t;
build_alternating_t=build_alternating_2_tmp_2;
build_alternating_t1=build_alternating_t1->nxt;
}
;
add_set(0,final_set,node_id);
break_1$=1;
}
;
if ((nm_6$==V_OPER) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
build_alternating_t1=build_alternating(0,p->rgt);
while(build_alternating_t1){build_alternating_t2=build_alternating(0,p->lft);
while(build_alternating_t2){build_alternating_2_tmp_3=merge_trans(0,build_alternating_t1,build_alternating_t2);
if (build_alternating_2_tmp_3){build_alternating_2_tmp_3->nxt=build_alternating_t;
build_alternating_t=build_alternating_2_tmp_3;
}
;
build_alternating_t2=build_alternating_t2->nxt;
}
;
build_alternating_2_tmp_3=dup_trans(0,build_alternating_t1);
add_set(0,build_alternating_2_tmp_3->to,node_id);
build_alternating_2_tmp_3->nxt=build_alternating_t;
build_alternating_t=build_alternating_2_tmp_3;
build_alternating_t1=build_alternating_t1->nxt;
}
;
break_1$=1;
}
;
if ((nm_6$==AND_1) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
build_alternating_t=NULL;
build_alternating_t1=build_alternating(0,p->lft);
while(build_alternating_t1){build_alternating_t2=build_alternating(0,p->rgt);
while(build_alternating_t2){build_alternating_2_tmp_4=merge_trans(0,build_alternating_t1,build_alternating_t2);
if (build_alternating_2_tmp_4){build_alternating_2_tmp_4->nxt=build_alternating_t;
build_alternating_t=build_alternating_2_tmp_4;
}
;
build_alternating_t2=build_alternating_t2->nxt;
}
;
build_alternating_t1=build_alternating_t1->nxt;
}
;
break_1$=1;
}
;
if ((nm_6$==OR_1) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
build_alternating_t=NULL;
build_alternating_t1=build_alternating(0,p->lft);
while(build_alternating_t1){build_alternating_2_tmp_5=dup_trans(0,build_alternating_t1);
build_alternating_2_tmp_5->nxt=build_alternating_t;
build_alternating_t=build_alternating_2_tmp_5;
build_alternating_t1=build_alternating_t1->nxt;
}
;
build_alternating_t1=build_alternating(0,p->rgt);
while(build_alternating_t1){build_alternating_2_tmp_6=dup_trans(0,build_alternating_t1);
build_alternating_2_tmp_6->nxt=build_alternating_t;
build_alternating_t=build_alternating_2_tmp_6;
build_alternating_t1=build_alternating_t1->nxt;
}
;
break_1$=1;
}
;
if ((break_1$==0) && (return_1==0)){break_1$=1;
}
;
transition[node_id]=build_alternating_t;
label[node_id]=p;
node_id=(node_id)+(1);
return_1=1;
RValue=build_alternating_t;
}
;
return RValue;
}
void  simplify_atrans(int $$Ext,ATrans** trans){
int continue_1;
int break_1;
struct ATrans *simplify_atrans_t,*simplify_atrans_father;
struct ATrans *simplify_atrans_t1;
continue_1=0;
break_1=0;
simplify_atrans_father=NULL;
continue_1=0;
simplify_atrans_t=(*(trans));
while(simplify_atrans_t){continue_1=0;
break_1=0;
simplify_atrans_t1=(*(trans));
while((break_1==0) && (simplify_atrans_t1)){if (((((simplify_atrans_t1)!=(simplify_atrans_t)) && (included_set(1,simplify_atrans_t1->to,simplify_atrans_t->to,0))) && (included_set(1,simplify_atrans_t1->pos,simplify_atrans_t->pos,1))) && (included_set(1,simplify_atrans_t1->neg,simplify_atrans_t->neg,1))){break_1=1;
}
;
if (break_1==0){simplify_atrans_t1=simplify_atrans_t1->nxt;
}
;
}
;
break_1=0;
if (simplify_atrans_t1){if (simplify_atrans_father){simplify_atrans_father->nxt=simplify_atrans_t->nxt;
} else {(*(trans))=simplify_atrans_t->nxt;
}
;
free_atrans(0,simplify_atrans_t,0);
if (simplify_atrans_father){simplify_atrans_t=simplify_atrans_father->nxt;
} else {simplify_atrans_t=(*(trans));
}
;
continue_1=1;
}
;
if (continue_1==0){atrans_count=(atrans_count)+(1);
simplify_atrans_father=simplify_atrans_t;
simplify_atrans_t=simplify_atrans_t->nxt;
}
;
}
;
continue_1=0;
}
void  simplify_astates(int $$Ext){
int continue_1;
struct ATrans *simplify_astates_t;
int simplify_astates_i,*simplify_astates_acc;
continue_1=0;
simplify_astates_acc=make_set(0,-1,0);
simplify_astates_t=transition[0];
while(simplify_astates_t){merge_sets(0,simplify_astates_acc,simplify_astates_t->to,0);
struct ATrans *$$$simplify_astates_t$0;
$$$simplify_astates_t$0=simplify_astates_t;
$$$simplify_astates_t$0=simplify_astates_t->nxt;
int $$$simplify_astates_i$1;
$$$simplify_astates_i$1=0;
simplify_astates_t=$$$simplify_astates_t$0;
simplify_astates_i=$$$simplify_astates_i$1;
}
;
continue_1=0;
simplify_astates_i=(node_id)-(1);
while(simplify_astates_i>0){continue_1=0;
if (!(in_set(1,simplify_astates_acc,simplify_astates_i))){label[simplify_astates_i]=NULL;
free_atrans(0,transition[simplify_astates_i],1);
transition[simplify_astates_i]=NULL;
continue_1=1;
simplify_astates_i=(simplify_astates_i)-(1);
}
;
if (continue_1==0){astate_count=(astate_count)+(1);
simplify_atrans(0,&transition[simplify_astates_i]);
simplify_astates_t=transition[simplify_astates_i];
while(simplify_astates_t){merge_sets(0,simplify_astates_acc,simplify_astates_t->to,0);
simplify_astates_t=simplify_astates_t->nxt;
}
;
simplify_astates_i=(simplify_astates_i)-(1);
}
;
}
;
continue_1=0;
tfree(0,simplify_astates_acc);
}
void  print_alternating(int $$Ext){
int continue_1;
int print_alternating_i;
struct ATrans *print_alternating_t;
continue_1=0;
printf("init :\n");
print_alternating_t=transition[0];
while(print_alternating_t){print_set(0,print_alternating_t->to,0);
printf("\n");
print_alternating_t=print_alternating_t->nxt;
}
;
continue_1=0;
print_alternating_i=(node_id)-(1);
while(print_alternating_i>0){continue_1=0;
if (!(label[print_alternating_i])){continue_1=1;
print_alternating_i=(print_alternating_i)-(1);
}
;
if (continue_1==0){printf("state ");
printf("%d",print_alternating_i);
printf("i : ");
dump(0,label[print_alternating_i]);
printf("\n");
print_alternating_t=transition[print_alternating_i];
while(print_alternating_t){if ((empty_set(1,print_alternating_t->pos,1)) && (empty_set(1,print_alternating_t->neg,1))){printf("1");
}
;
print_set(0,print_alternating_t->pos,1);
if ((!(empty_set(1,print_alternating_t->pos,1))) && (!(empty_set(1,print_alternating_t->neg,1)))){printf(" & ");
}
;
print_set(0,print_alternating_t->neg,2);
printf(" -> ");
print_set(0,print_alternating_t->to,0);
printf("\n");
print_alternating_t=print_alternating_t->nxt;
}
;
print_alternating_i=(print_alternating_i)-(1);
}
;
}
;
continue_1=0;
}
void  mk_alternating(int $$Ext,Node* p){
node_size=(calculate_node_size(1,p))+(1);
label=(Node**)(tl_emalloc(1,(node_size*4)));
transition=(ATrans**)(tl_emalloc(1,(node_size*4)));
node_size=((node_size/ (8*4)))+(1);
sym_size=calculate_sym_size(0,p);
if (sym_size){sym_table=(char**)(tl_emalloc(1,(sym_size*4)));
}
;
sym_size=((sym_size/ (8*4)))+(1);
final_set=make_set(0,-1,0);
transition[0]=boolean(0,p);
if (tl_verbose){printf("\nAlternating automaton before simplification\n");
print_alternating(0);
}
;
if (tl_simp_diff){simplify_astates(0);
if (tl_verbose){printf("\nAlternating automaton after simplification\n");
print_alternating(0);
}
;
}
;
releasenode(0,1,p);
tfree(0,label);
}
void  free_bstate(int $$Ext,BState* s){
free_btrans(0,s->trans->nxt,s->trans,1);
tfree(0,s);
}
BState*  remove_bstate(int $$Ext,BState* s,BState* s1){
BState*  RValue=0;
int return_1;
struct BState *remove_bstate_prv;
return_1=0;
remove_bstate_prv=s->prv;
s->prv->nxt=s->nxt;
s->nxt->prv=s->prv;
free_btrans(0,s->trans->nxt,s->trans,0);
s->trans=NULL;
s->nxt=bremoved->nxt;
bremoved->nxt=s;
s->prv=s1;
s1=bremoved->nxt;
while((s1)!=(bremoved)){if (s1->prv==s){s1->prv=s->prv;
}
;
s1=s1->nxt;
}
;
return_1=1;
RValue=remove_bstate_prv;
return RValue;
}
void  copy_btrans(int $$Ext,BTrans* from,BTrans* to){
to->to=from->to;
copy_set(0,from->pos,to->pos,1);
copy_set(0,from->neg,to->neg,1);
}
int  simplify_btrans(int $$Ext){
int  RValue=0;
int return_1;
struct BState *simplify_btrans_s;
struct BTrans *simplify_btrans_t,*simplify_btrans_t1;
int simplify_btrans_changed;
struct BTrans *simplify_btrans_1_3_free;
return_1=0;
simplify_btrans_changed=0;
simplify_btrans_s=bstates->nxt;
while((simplify_btrans_s)!=(bstates)){simplify_btrans_t=simplify_btrans_s->trans->nxt;
while((simplify_btrans_t)!=(simplify_btrans_s->trans)){simplify_btrans_t1=simplify_btrans_s->trans->nxt;
copy_btrans(0,simplify_btrans_t,simplify_btrans_s->trans);
while((((simplify_btrans_t==simplify_btrans_t1) || ((simplify_btrans_t->to)!=(simplify_btrans_t1->to))) || (!(included_set(1,simplify_btrans_t1->pos,simplify_btrans_t->pos,1)))) || (!(included_set(1,simplify_btrans_t1->neg,simplify_btrans_t->neg,1)))){simplify_btrans_t1=simplify_btrans_t1->nxt;
}
;
if ((simplify_btrans_t1)!=(simplify_btrans_s->trans)){simplify_btrans_1_3_free=simplify_btrans_t->nxt;
simplify_btrans_t->to=simplify_btrans_1_3_free->to;
copy_set(0,simplify_btrans_1_3_free->pos,simplify_btrans_t->pos,1);
copy_set(0,simplify_btrans_1_3_free->neg,simplify_btrans_t->neg,1);
simplify_btrans_t->nxt=simplify_btrans_1_3_free->nxt;
if (simplify_btrans_1_3_free==simplify_btrans_s->trans){simplify_btrans_s->trans=simplify_btrans_t;
}
;
free_btrans(0,simplify_btrans_1_3_free,0,0);
simplify_btrans_changed=(simplify_btrans_changed)+(1);
} else {simplify_btrans_t=simplify_btrans_t->nxt;
}
;
}
;
simplify_btrans_s=simplify_btrans_s->nxt;
}
;
if (tl_stats){printf("\n");
printf("%d",simplify_btrans_changed);
printf("itions removed\n");
}
;
return_1=1;
RValue=simplify_btrans_changed;
return RValue;
}
int  same_btrans(int $$Ext,BTrans* s,BTrans* t){
int  RValue=0;
int return_1;
return_1=0;
return_1=1;
RValue=((s->to==t->to) && (same_sets(0,s->pos,t->pos,1))) && (same_sets(0,s->neg,t->neg,1));
return RValue;
}
void  remove_btrans(int $$Ext,BState* to){
struct BState *remove_btrans_s;
struct BTrans *remove_btrans_t;
int remove_btrans_i;
struct BTrans *remove_btrans_1_2_3_free;
remove_btrans_s=bstates->nxt;
while((remove_btrans_s)!=(bstates)){remove_btrans_t=remove_btrans_s->trans->nxt;
while((remove_btrans_t)!=(remove_btrans_s->trans)){if (remove_btrans_t->to==to){remove_btrans_1_2_3_free=remove_btrans_t->nxt;
remove_btrans_t->to=remove_btrans_1_2_3_free->to;
copy_set(0,remove_btrans_1_2_3_free->pos,remove_btrans_t->pos,1);
copy_set(0,remove_btrans_1_2_3_free->neg,remove_btrans_t->neg,1);
remove_btrans_t->nxt=remove_btrans_1_2_3_free->nxt;
if (remove_btrans_1_2_3_free==remove_btrans_s->trans){remove_btrans_s->trans=remove_btrans_t;
}
;
free_btrans(0,remove_btrans_1_2_3_free,0,0);
}
;
remove_btrans_t=remove_btrans_t->nxt;
}
;
remove_btrans_s=remove_btrans_s->nxt;
}
;
}
void  retarget_all_btrans(int $$Ext){
struct BState *retarget_all_btrans_s;
struct BTrans *retarget_all_btrans_t;
struct BTrans *retarget_all_btrans_1_2_3_4_free;
retarget_all_btrans_s=bstates->nxt;
while((retarget_all_btrans_s)!=(bstates)){retarget_all_btrans_t=retarget_all_btrans_s->trans->nxt;
while((retarget_all_btrans_t)!=(retarget_all_btrans_s->trans)){if (!(retarget_all_btrans_t->to->trans)){retarget_all_btrans_t->to=retarget_all_btrans_t->to->prv;
if (!(retarget_all_btrans_t->to)){retarget_all_btrans_1_2_3_4_free=retarget_all_btrans_t->nxt;
retarget_all_btrans_t->to=retarget_all_btrans_1_2_3_4_free->to;
copy_set(0,retarget_all_btrans_1_2_3_4_free->pos,retarget_all_btrans_t->pos,1);
copy_set(0,retarget_all_btrans_1_2_3_4_free->neg,retarget_all_btrans_t->neg,1);
retarget_all_btrans_t->nxt=retarget_all_btrans_1_2_3_4_free->nxt;
if (retarget_all_btrans_1_2_3_4_free==retarget_all_btrans_s->trans){retarget_all_btrans_s->trans=retarget_all_btrans_t;
}
;
free_btrans(0,retarget_all_btrans_1_2_3_4_free,0,0);
}
;
}
;
retarget_all_btrans_t=retarget_all_btrans_t->nxt;
}
;
retarget_all_btrans_s=retarget_all_btrans_s->nxt;
}
;
while((bremoved->nxt)!=(bremoved)){retarget_all_btrans_s=bremoved->nxt;
bremoved->nxt=bremoved->nxt->nxt;
tfree(0,retarget_all_btrans_s);
}
;
}
int  all_btrans_match(int $$Ext,BState* a,BState* b){
int  RValue=0;
int return_1;
struct BTrans *all_btrans_match_s,*all_btrans_match_t;
return_1=0;
if (((((a->final==accept) || (b->final==accept)) && (((a->final)+(b->final))!=((2*accept)))) && (a->incoming>=0)) && (b->incoming>=0)){return_1=1;
RValue=0;
}
;
if (return_1==0){all_btrans_match_s=a->trans->nxt;
while((return_1==0) && ((all_btrans_match_s)!=(a->trans))){copy_btrans(0,all_btrans_match_s,b->trans);
all_btrans_match_t=b->trans->nxt;
while(!(same_btrans(1,all_btrans_match_s,all_btrans_match_t))){all_btrans_match_t=all_btrans_match_t->nxt;
}
;
if (all_btrans_match_t==b->trans){return_1=1;
RValue=0;
}
;
if (return_1==0){all_btrans_match_s=all_btrans_match_s->nxt;
}
;
}
;
if (return_1==0){all_btrans_match_s=b->trans->nxt;
while((return_1==0) && ((all_btrans_match_s)!=(b->trans))){copy_btrans(0,all_btrans_match_s,a->trans);
all_btrans_match_t=a->trans->nxt;
while(!(same_btrans(1,all_btrans_match_s,all_btrans_match_t))){all_btrans_match_t=all_btrans_match_t->nxt;
}
;
if (all_btrans_match_t==a->trans){return_1=1;
RValue=0;
}
;
if (return_1==0){all_btrans_match_s=all_btrans_match_s->nxt;
}
;
}
;
if (return_1==0){return_1=1;
RValue=1;
}
;
}
;
}
;
return RValue;
}
int  simplify_bstates(int $$Ext){
int  RValue=0;
int continue_1;
int return_1;
struct BState *simplify_bstates_s,*simplify_bstates_s1;
int simplify_bstates_changed;
continue_1=0;
return_1=0;
simplify_bstates_changed=0;
continue_1=0;
simplify_bstates_s=bstates->nxt;
while((simplify_bstates_s)!=(bstates)){continue_1=0;
if (simplify_bstates_s->trans==simplify_bstates_s->trans->nxt){simplify_bstates_s=remove_bstate(0,simplify_bstates_s,NULL);
simplify_bstates_changed=(simplify_bstates_changed)+(1);
continue_1=1;
simplify_bstates_s=simplify_bstates_s->nxt;
}
;
if (continue_1==0){bstates->trans=simplify_bstates_s->trans;
bstates->final=simplify_bstates_s->final;
simplify_bstates_s1=simplify_bstates_s->nxt;
while(!(all_btrans_match(1,simplify_bstates_s,simplify_bstates_s1))){simplify_bstates_s1=simplify_bstates_s1->nxt;
}
;
if ((simplify_bstates_s1)!=(bstates)){if (simplify_bstates_s1->incoming==-1){simplify_bstates_s1->final=simplify_bstates_s->final;
}
;
simplify_bstates_s=remove_bstate(0,simplify_bstates_s,simplify_bstates_s1);
simplify_bstates_changed=(simplify_bstates_changed)+(1);
}
;
simplify_bstates_s=simplify_bstates_s->nxt;
}
;
}
;
continue_1=0;
retarget_all_btrans(0);
return_1=1;
RValue=simplify_bstates_changed;
return RValue;
}
int  bdfs(int $$Ext,BState* s){
int  RValue=0;
int break_1;
int return_1;
struct BTrans *bdfs_t;
struct BScc *bdfs_c;
struct BScc *bdfs_scc;
int bdfs_1_result;
break_1=0;
return_1=0;
bdfs_scc=(BScc*)(tl_emalloc(1,16));
bdfs_scc->bstate=s;
bdfs_scc->rank=rank;
bdfs_scc->theta=rank;
rank=(rank)+(1);
bdfs_scc->nxt=Bscc_stack;
Bscc_stack=bdfs_scc;
s->incoming=1;
bdfs_t=s->trans->nxt;
while((bdfs_t)!=(s->trans)){if (bdfs_t->to->incoming==0){bdfs_1_result=bdfs(0,bdfs_t->to);
bdfs_scc->theta=((bdfs_scc->theta<bdfs_1_result) ?bdfs_scc->theta : bdfs_1_result );
} else {break_1=0;
bdfs_c=Bscc_stack->nxt;
while((break_1==0) && ((bdfs_c)!=(0))){if (bdfs_c->bstate==bdfs_t->to){bdfs_scc->theta=((bdfs_scc->theta<bdfs_c->rank) ?bdfs_scc->theta : bdfs_c->rank );
break_1=1;
}
;
if (break_1==0){bdfs_c=bdfs_c->nxt;
}
;
}
;
break_1=0;
}
;
bdfs_t=bdfs_t->nxt;
}
;
if (bdfs_scc->rank==bdfs_scc->theta){if (Bscc_stack==bdfs_scc){s->incoming=-1;
bdfs_t=s->trans->nxt;
while((bdfs_t)!=(s->trans)){if (bdfs_t->to==s){s->incoming=1;
}
;
bdfs_t=bdfs_t->nxt;
}
;
}
;
Bscc_stack=bdfs_scc->nxt;
}
;
return_1=1;
RValue=bdfs_scc->theta;
return RValue;
}
void  simplify_bscc(int $$Ext){
int return_1;
struct BState *simplify_bscc_s;
return_1=0;
rank=1;
Bscc_stack=0;
if (bstates==bstates->nxt){return_1=1;
}
;
if (return_1==0){simplify_bscc_s=bstates->nxt;
while((simplify_bscc_s)!=(bstates)){simplify_bscc_s->incoming=0;
simplify_bscc_s=simplify_bscc_s->nxt;
}
;
bdfs(0,bstates->prv);
simplify_bscc_s=bstates->nxt;
while((simplify_bscc_s)!=(bstates)){if (simplify_bscc_s->incoming==0){remove_bstate(0,simplify_bscc_s,0);
}
;
simplify_bscc_s=simplify_bscc_s->nxt;
}
;
}
;
}
BState*  find_bstate(int $$Ext,GState** state,int final,BState* s){
BState*  RValue=0;
int return_1;
return_1=0;
if ((s->gstate==(*(state))) && (s->final==final)){return_1=1;
RValue=s;
}
;
if (return_1==0){s=bstack->nxt;
bstack->gstate=(*(state));
bstack->final=final;
while((!(s->gstate==(*(state)))) || (!(s->final==final))){s=s->nxt;
}
;
if ((s)!=(bstack)){return_1=1;
RValue=s;
}
;
if (return_1==0){s=bstates->nxt;
bstates->gstate=(*(state));
bstates->final=final;
while((!(s->gstate==(*(state)))) || (!(s->final==final))){s=s->nxt;
}
;
if ((s)!=(bstates)){return_1=1;
RValue=s;
}
;
if (return_1==0){s=bremoved->nxt;
bremoved->gstate=(*(state));
bremoved->final=final;
while((!(s->gstate==(*(state)))) || (!(s->final==final))){s=s->nxt;
}
;
if ((s)!=(bremoved)){return_1=1;
RValue=s;
}
;
if (return_1==0){s=(BState*)(tl_emalloc(1,28));
s->gstate=(*(state));
s->id=(*(state))->id;
s->incoming=0;
s->final=final;
s->trans=emalloc_btrans(0);
s->trans->nxt=s->trans;
s->nxt=bstack->nxt;
bstack->nxt=s;
return_1=1;
RValue=s;
}
;
}
;
}
;
}
;
return RValue;
}
int  next_final(int $$Ext,int *set,int fin$){
int  RValue=0;
int return_1;
return_1=0;
if (((fin$)!=(accept)) && (in_set(1,set,final[(fin$)+(1)]))){return_1=1;
RValue=next_final(0,set,(fin$)+(1));
}
;
if (return_1==0){return_1=1;
RValue=fin$;
}
;
return RValue;
}
void  make_btrans(int $$Ext,BState* s){
int break_1;
int return_1;
int make_btrans_state_trans;
struct GTrans *make_btrans_t;
struct BTrans *make_btrans_t1;
struct BState *make_btrans_s1;
int make_btrans_1_fin$;
struct BState *make_btrans_1_to;
struct BTrans *make_btrans_1_2_free;
struct BTrans *make_btrans_1_7_trans;
break_1=0;
return_1=0;
make_btrans_state_trans=0;
if (s->gstate->trans){make_btrans_t=s->gstate->trans->nxt;
while((make_btrans_t)!=(s->gstate->trans)){make_btrans_1_fin$=next_final(0,make_btrans_t->final,((s->final==accept) ?0 : s->final ));
make_btrans_1_to=find_bstate(0,&make_btrans_t->to,make_btrans_1_fin$,s);
break_1=0;
make_btrans_t1=s->trans->nxt;
while((break_1==0) && ((make_btrans_t1)!=(s->trans))){if ((((tl_simp_fly) && (make_btrans_1_to==make_btrans_t1->to)) && (included_set(1,make_btrans_t->pos,make_btrans_t1->pos,1))) && (included_set(1,make_btrans_t->neg,make_btrans_t1->neg,1))){make_btrans_1_2_free=make_btrans_t1->nxt;
make_btrans_t1->to->incoming=(make_btrans_t1->to->incoming)-(1);
make_btrans_t1->to=make_btrans_1_2_free->to;
copy_set(0,make_btrans_1_2_free->pos,make_btrans_t1->pos,1);
copy_set(0,make_btrans_1_2_free->neg,make_btrans_t1->neg,1);
make_btrans_t1->nxt=make_btrans_1_2_free->nxt;
if (make_btrans_1_2_free==s->trans){s->trans=make_btrans_t1;
}
;
free_btrans(0,make_btrans_1_2_free,0,0);
make_btrans_state_trans=(make_btrans_state_trans)-(1);
} else {if ((((tl_simp_fly) && (make_btrans_t1->to==make_btrans_1_to)) && (included_set(1,make_btrans_t1->pos,make_btrans_t->pos,1))) && (included_set(1,make_btrans_t1->neg,make_btrans_t->neg,1))){break_1=1;
} else {make_btrans_t1=make_btrans_t1->nxt;
}
;
}
;
}
;
break_1=0;
if (make_btrans_t1==s->trans){make_btrans_1_7_trans=emalloc_btrans(0);
make_btrans_1_7_trans->to=make_btrans_1_to;
make_btrans_1_7_trans->to->incoming=(make_btrans_1_7_trans->to->incoming)+(1);
copy_set(0,make_btrans_t->pos,make_btrans_1_7_trans->pos,1);
copy_set(0,make_btrans_t->neg,make_btrans_1_7_trans->neg,1);
make_btrans_1_7_trans->nxt=s->trans->nxt;
s->trans->nxt=make_btrans_1_7_trans;
make_btrans_state_trans=(make_btrans_state_trans)+(1);
}
;
make_btrans_t=make_btrans_t->nxt;
}
;
}
;
if (tl_simp_fly){if (s->trans==s->trans->nxt){free_btrans(0,s->trans->nxt,s->trans,1);
s->trans=NULL;
s->prv=NULL;
s->nxt=bremoved->nxt;
bremoved->nxt=s;
make_btrans_s1=bremoved->nxt;
while((make_btrans_s1)!=(bremoved)){if (make_btrans_s1->prv==s){make_btrans_s1->prv=NULL;
}
;
make_btrans_s1=make_btrans_s1->nxt;
}
;
return_1=1;
}
;
if (return_1==0){bstates->trans=s->trans;
bstates->final=s->final;
make_btrans_s1=bstates->nxt;
while(!(all_btrans_match(1,s,make_btrans_s1))){make_btrans_s1=make_btrans_s1->nxt;
}
;
if ((make_btrans_s1)!=(bstates)){free_btrans(0,s->trans->nxt,s->trans,1);
s->trans=NULL;
s->prv=make_btrans_s1;
s->nxt=bremoved->nxt;
bremoved->nxt=s;
make_btrans_s1=bremoved->nxt;
while((make_btrans_s1)!=(bremoved)){if (make_btrans_s1->prv==s){make_btrans_s1->prv=s->prv;
}
;
make_btrans_s1=make_btrans_s1->nxt;
}
;
return_1=1;
}
;
}
;
}
;
if (return_1==0){s->nxt=bstates->nxt;
s->prv=bstates;
s->nxt->prv=s;
bstates->nxt=s;
btrans_count=(btrans_count)+(make_btrans_state_trans);
bstate_count=(bstate_count)+(1);
}
;
}
void  print_buchi(int $$Ext,BState* s){
int return_1;
struct BTrans *print_buchi_t;
return_1=0;
if (s==bstates){return_1=1;
}
;
if (return_1==0){print_buchi(0,s->nxt);
printf("state ");
if (s->id==-1){printf("init");
} else {if (s->final==accept){printf("accept");
} else {printf("T");
;
printf("i");
}
;
printf("_");
;
printf("i");
}
;
printf("\n");
print_buchi_t=s->trans->nxt;
while((print_buchi_t)!=(s->trans)){if ((empty_set(1,print_buchi_t->pos,1)) && (empty_set(1,print_buchi_t->neg,1))){printf("1");
}
;
print_set(0,print_buchi_t->pos,1);
if ((!(empty_set(1,print_buchi_t->pos,1))) && (!(empty_set(1,print_buchi_t->neg,1)))){printf(" & ");
}
;
print_set(0,print_buchi_t->neg,2);
printf(" -> ");
if (print_buchi_t->to->id==-1){printf("init\n");
} else {if (print_buchi_t->to->final==accept){printf("accept");
} else {printf("T");
;
printf("i");
}
;
printf("_");
;
printf("i\n");
}
;
print_buchi_t=print_buchi_t->nxt;
}
;
}
;
}
void  print_spin_buchi(int $$Ext){
int continue_1;
int return_1;
struct BTrans *print_spin_buchi_t;
struct BState *print_spin_buchi_s;
int print_spin_buchi_accept_all,print_spin_buchi_init_count;
struct BTrans *print_spin_buchi_t1;
continue_1=0;
return_1=0;
print_spin_buchi_accept_all=0;
print_spin_buchi_init_count=0;
if (bstates->nxt==bstates){printf("never {\n         \n");
printf("T0_init:\n");
printf("\tfalse;\n");
printf("}\n");
return_1=1;
}
;
if (return_1==0){if ((bstates->nxt->nxt==bstates) && (bstates->nxt->id==0)){printf("never {\n             \n");
printf("accept_init:\n");
printf("\tif\n");
printf("\t:: (1) -> goto_1 accept_init\n");
printf("\tfi;\n");
printf("}\n");
return_1=1;
}
;
if (return_1==0){printf("never {\n             \n");
continue_1=0;
print_spin_buchi_s=bstates->prv;
while((print_spin_buchi_s)!=(bstates)){continue_1=0;
if (print_spin_buchi_s->id==0){print_spin_buchi_accept_all=1;
continue_1=1;
print_spin_buchi_s=print_spin_buchi_s->prv;
}
;
if (continue_1==0){if (print_spin_buchi_s->final==accept){printf("accept_");
} else {printf("T");
;
printf("i_");
}
;
if (print_spin_buchi_s->id==-1){printf("init:\n");
} else {printf("S");
;
printf("i:\n");
}
;
if (print_spin_buchi_s->trans->nxt==print_spin_buchi_s->trans){printf("\tfalse;\n");
continue_1=1;
print_spin_buchi_s=print_spin_buchi_s->prv;
}
;
if (continue_1==0){printf("\tif\n");
print_spin_buchi_t=print_spin_buchi_s->trans->nxt;
while((print_spin_buchi_t)!=(print_spin_buchi_s->trans)){printf("\t:: (");
spin_print_set(0,print_spin_buchi_t->pos,print_spin_buchi_t->neg);
print_spin_buchi_t1=print_spin_buchi_t;
while((print_spin_buchi_t1->nxt)!=(print_spin_buchi_s->trans)){if ((print_spin_buchi_t1->nxt->to->id==print_spin_buchi_t->to->id) && (print_spin_buchi_t1->nxt->to->final==print_spin_buchi_t->to->final)){printf(") || (");
spin_print_set(0,print_spin_buchi_t1->nxt->pos,print_spin_buchi_t1->nxt->neg);
print_spin_buchi_t1->nxt=print_spin_buchi_t1->nxt->nxt;
} else {print_spin_buchi_t1=print_spin_buchi_t1->nxt;
}
;
}
;
printf(") -> goto_1 ");
if (print_spin_buchi_t->to->final==accept){printf("accept_");
} else {printf("T");
;
printf("i_");
}
;
if (print_spin_buchi_t->to->id==0){printf("all\n");
} else {if (print_spin_buchi_t->to->id==-1){printf("init\n");
} else {printf("S");
;
printf("i\n");
}
;
}
;
print_spin_buchi_t=print_spin_buchi_t->nxt;
}
;
printf("\tfi;\n");
print_spin_buchi_s=print_spin_buchi_s->prv;
}
;
}
;
}
;
continue_1=0;
if (print_spin_buchi_accept_all){printf("accept_all:\n");
printf("\tskip\n");
}
;
printf("}\n");
}
;
}
;
}
void  mk_buchi(int $$Ext){
int continue_1;
int break_1;
int mk_buchi_i;
struct BState *mk_buchi_s;
struct GTrans *mk_buchi_t;
struct BTrans *mk_buchi_t1;
int mk_buchi_1_fin$;
struct BState *mk_buchi_1_to;
struct BTrans *mk_buchi_1_2_free;
struct BTrans *mk_buchi_1_7_trans;
continue_1=0;
break_1=0;
mk_buchi_s=(BState*)(tl_emalloc(1,28));
rank=0;
accept=(final[0])-(1);
bstack=(BState*)(tl_emalloc(1,28));
bstack->nxt=bstack;
bremoved=(BState*)(tl_emalloc(1,28));
bremoved->nxt=bremoved;
bstates=(BState*)(tl_emalloc(1,28));
bstates->nxt=mk_buchi_s;
bstates->prv=mk_buchi_s;
mk_buchi_s->nxt=bstates;
mk_buchi_s->prv=bstates;
mk_buchi_s->id=-1;
mk_buchi_s->incoming=1;
mk_buchi_s->final=0;
mk_buchi_s->gstate=0;
mk_buchi_s->trans=emalloc_btrans(0);
mk_buchi_s->trans->nxt=mk_buchi_s->trans;
mk_buchi_i=0;
while(mk_buchi_i<init_size){if (init[mk_buchi_i]){mk_buchi_t=init[mk_buchi_i]->trans->nxt;
while((mk_buchi_t)!=(init[mk_buchi_i]->trans)){mk_buchi_1_fin$=next_final(0,mk_buchi_t->final,0);
mk_buchi_1_to=find_bstate(0,&mk_buchi_t->to,mk_buchi_1_fin$,mk_buchi_s);
break_1=0;
mk_buchi_t1=mk_buchi_s->trans->nxt;
while((break_1==0) && ((mk_buchi_t1)!=(mk_buchi_s->trans))){if ((((tl_simp_fly) && (mk_buchi_1_to==mk_buchi_t1->to)) && (included_set(1,mk_buchi_t->pos,mk_buchi_t1->pos,1))) && (included_set(1,mk_buchi_t->neg,mk_buchi_t1->neg,1))){mk_buchi_1_2_free=mk_buchi_t1->nxt;
mk_buchi_t1->to->incoming=(mk_buchi_t1->to->incoming)-(1);
mk_buchi_t1->to=mk_buchi_1_2_free->to;
copy_set(0,mk_buchi_1_2_free->pos,mk_buchi_t1->pos,1);
copy_set(0,mk_buchi_1_2_free->neg,mk_buchi_t1->neg,1);
mk_buchi_t1->nxt=mk_buchi_1_2_free->nxt;
if (mk_buchi_1_2_free==mk_buchi_s->trans){mk_buchi_s->trans=mk_buchi_t1;
}
;
free_btrans(0,mk_buchi_1_2_free,0,0);
} else {if ((((tl_simp_fly) && (mk_buchi_t1->to==mk_buchi_1_to)) && (included_set(1,mk_buchi_t1->pos,mk_buchi_t->pos,1))) && (included_set(1,mk_buchi_t1->neg,mk_buchi_t->neg,1))){break_1=1;
} else {mk_buchi_t1=mk_buchi_t1->nxt;
}
;
}
;
}
;
break_1=0;
if (mk_buchi_t1==mk_buchi_s->trans){mk_buchi_1_7_trans=emalloc_btrans(0);
mk_buchi_1_7_trans->to=mk_buchi_1_to;
mk_buchi_1_7_trans->to->incoming=(mk_buchi_1_7_trans->to->incoming)+(1);
copy_set(0,mk_buchi_t->pos,mk_buchi_1_7_trans->pos,1);
copy_set(0,mk_buchi_t->neg,mk_buchi_1_7_trans->neg,1);
mk_buchi_1_7_trans->nxt=mk_buchi_s->trans->nxt;
mk_buchi_s->trans->nxt=mk_buchi_1_7_trans;
}
;
mk_buchi_t=mk_buchi_t->nxt;
}
;
}
;
mk_buchi_i=(mk_buchi_i)+(1);
}
;
while((bstack->nxt)!=(bstack)){continue_1=0;
mk_buchi_s=bstack->nxt;
bstack->nxt=bstack->nxt->nxt;
if (!(mk_buchi_s->incoming)){free_bstate(0,mk_buchi_s);
continue_1=1;
}
;
if (continue_1==0){make_btrans(0,mk_buchi_s);
}
;
}
;
continue_1=0;
retarget_all_btrans(0);
if (tl_verbose){printf("\nBuchi automaton before simplification\n");
print_buchi(0,bstates->nxt);
if (bstates==bstates->nxt){printf("empty automaton, refuses all words\n");
}
;
}
;
if (tl_simp_diff){simplify_btrans(0);
if (tl_simp_scc){simplify_bscc(0);
}
;
while(simplify_bstates(1)){simplify_btrans(0);
if (tl_simp_scc){simplify_bscc(0);
}
;
}
;
if (tl_verbose){printf("\nBuchi automaton after simplification\n");
print_buchi(0,bstates->nxt);
if (bstates==bstates->nxt){printf("empty automaton, refuses all words\n");
}
;
printf("\n");
}
;
}
;
print_spin_buchi(0);
}
void  cache_dump(int $$Ext){
int continue_1;
struct Cache *cache_dump_d;
int cache_dump_nr;
continue_1=0;
cache_dump_nr=0;
printf("\nCACHE DUMP:\n");
continue_1=0;
cache_dump_d=stored;
while(cache_dump_d){continue_1=0;
if (cache_dump_d->same){continue_1=1;
struct Cache *$$$cache_dump_d$2;
$$$cache_dump_d$2=cache_dump_d;
$$$cache_dump_d$2=cache_dump_d->nxt;
int $$$cache_dump_nr$3;
$$$cache_dump_nr$3=(cache_dump_nr)+(1);
cache_dump_d=$$$cache_dump_d$2;
cache_dump_nr=$$$cache_dump_nr$3;
}
;
if (continue_1==0){printf("B");
printf("%d",cache_dump_nr);
printf(": ");
dump(0,cache_dump_d->before);
printf("\n");
printf("A");
printf("%d",cache_dump_nr);
printf(": ");
dump(0,cache_dump_d->after);
printf("\n");
struct Cache *$$$cache_dump_d$4;
$$$cache_dump_d$4=cache_dump_d;
$$$cache_dump_d$4=cache_dump_d->nxt;
int $$$cache_dump_nr$5;
$$$cache_dump_nr$5=(cache_dump_nr)+(1);
cache_dump_d=$$$cache_dump_d$4;
cache_dump_nr=$$$cache_dump_nr$5;
}
;
}
;
continue_1=0;
printf("============\n");
}
Node*  in_cache(int $$Ext,Node* n){
Node*  RValue=0;
int return_1;
struct Cache *in_cache_d;
int in_cache_nr;
return_1=0;
in_cache_nr=0;
in_cache_d=stored;
while(in_cache_d){in_cache_d->same=0;
in_cache_d=in_cache_d->nxt;
}
;
in_cache_d=stored;
while((return_1==0) && (in_cache_d)){if (isequal(1,in_cache_d->before,n)){CacheHits=(CacheHits)+(1);
if ((in_cache_d->same) && (ismatch(1,n,in_cache_d->before))){return_1=1;
RValue=n;
}
;
if (return_1==0){return_1=1;
RValue=dupnode(0,in_cache_d->after);
}
;
}
;
if (return_1==0){if (return_1==0){struct Cache *$$$in_cache_d$6;
$$$in_cache_d$6=in_cache_d;
$$$in_cache_d$6=in_cache_d->nxt;
int $$$in_cache_nr$7;
$$$in_cache_nr$7=(in_cache_nr)+(1);
in_cache_d=$$$in_cache_d$6;
in_cache_nr=$$$in_cache_nr$7;
}
;
}
;
}
;
if (return_1==0){return_1=1;
RValue=NULL;
}
;
return RValue;
}
Node*  cached(int $$Ext,Node* n){
Node*  RValue=0;
int return_1;
struct Cache *cached_d;
struct Node *cached_m;
return_1=0;
if (!n){return_1=1;
RValue=n;
}
;
if (return_1==0){cached_m=in_cache(0,n);
if (cached_m){return_1=1;
RValue=cached_m;
}
;
if (return_1==0){Caches=(Caches)+(1);
cached_d=(Cache*)(tl_emalloc(1,16));
cached_d->before=dupnode(0,n);
cached_d->after=Canonical(0,n);
if (ismatch(1,cached_d->before,cached_d->after)){cached_d->same=1;
releasenode(0,1,cached_d->after);
cached_d->after=cached_d->before;
}
;
cached_d->nxt=stored;
stored=cached_d;
return_1=1;
RValue=dupnode(0,cached_d->after);
}
;
}
;
return RValue;
}
void  cache_stats(int $$Ext){
printf("cache stores     : ");
printf("%d",Caches);
printf("\n");
printf("cache hits       : ");
printf("%d",CacheHits);
printf("\n");
}
void  releasenode(int $$Ext,int all_levels,Node* n){
int return_1;
return_1=0;
if (!n){return_1=1;
}
;
if (return_1==0){if (all_levels){releasenode(0,1,n->lft);
n->lft=NULL;
releasenode(0,1,n->rgt);
n->rgt=NULL;
}
;
tfree(0,n);
}
;
}
Node*  tl_nn(int $$Ext,int t,Node* ll,Node* rl){
Node*  RValue=0;
int return_1;
struct Node *tl_nn_n;
return_1=0;
tl_nn_n=(Node*)(tl_emalloc(1,20));
tl_nn_n->ntyp=(int)(t);
tl_nn_n->lft=ll;
tl_nn_n->rgt=rl;
return_1=1;
RValue=tl_nn_n;
return RValue;
}
Node*  getnode(int $$Ext,Node* p){
Node*  RValue=0;
int return_1;
struct Node *getnode_n;
return_1=0;
if (!p){return_1=1;
RValue=p;
}
;
if (return_1==0){getnode_n=(Node*)(tl_emalloc(1,20));
getnode_n->ntyp=p->ntyp;
getnode_n->sym=p->sym;
getnode_n->lft=p->lft;
getnode_n->rgt=p->rgt;
return_1=1;
RValue=getnode_n;
}
;
return RValue;
}
Node*  dupnode(int $$Ext,Node* n){
Node*  RValue=0;
int return_1;
struct Node *dupnode_d;
return_1=0;
if (!n){return_1=1;
RValue=n;
}
;
if (return_1==0){dupnode_d=getnode(0,n);
dupnode_d->lft=dupnode(0,n->lft);
dupnode_d->rgt=dupnode(0,n->rgt);
return_1=1;
RValue=dupnode_d;
}
;
return RValue;
}
int  one_lft(int $$Ext,int ntyp,Node* x,Node* in){
int  RValue=0;
int return_1;
return_1=0;
if (!x){return_1=1;
RValue=1;
}
;
if (return_1==0){if (!in){return_1=1;
RValue=0;
}
;
if (return_1==0){if (sameform(1,x,in)){return_1=1;
RValue=1;
}
;
if (return_1==0){if ((in->ntyp)!=(ntyp)){return_1=1;
RValue=0;
}
;
if (return_1==0){if (one_lft(1,ntyp,x,in->lft)){return_1=1;
RValue=1;
}
;
if (return_1==0){return_1=1;
RValue=one_lft(0,ntyp,x,in->rgt);
}
;
}
;
}
;
}
;
}
;
return RValue;
}
int  all_lfts(int $$Ext,int ntyp,Node* from,Node* in){
int  RValue=0;
int return_1;
return_1=0;
if (!from){return_1=1;
RValue=1;
}
;
if (return_1==0){if ((from->ntyp)!=(ntyp)){return_1=1;
RValue=one_lft(0,ntyp,from,in);
}
;
if (return_1==0){if (!(one_lft(1,ntyp,from->lft,in))){return_1=1;
RValue=0;
}
;
if (return_1==0){return_1=1;
RValue=all_lfts(0,ntyp,from->rgt,in);
}
;
}
;
}
;
return RValue;
}
int  sametrees(int $$Ext,int ntyp,Node* a,Node* b){
int  RValue=0;
int return_1;
return_1=0;
if (!(all_lfts(1,ntyp,a,b))){return_1=1;
RValue=0;
}
;
if (return_1==0){return_1=1;
RValue=all_lfts(0,ntyp,b,a);
}
;
return RValue;
}
int  sameform(int $$Ext,Node* a,Node* b){
int  RValue=0;
int return_1;
int switch_1;
int break_1$;
int nm_7$;
return_1=0;
if ((!a) && (!b)){return_1=1;
RValue=1;
}
;
if (return_1==0){if ((!a) || (!b)){return_1=1;
RValue=0;
}
;
if (return_1==0){if ((a->ntyp)!=(b->ntyp)){return_1=1;
RValue=0;
}
;
if (return_1==0){if (((a->sym) && (b->sym)) && ((strcmp(a->sym->name,b->sym->name))!=(0))){return_1=1;
RValue=0;
}
;
if (return_1==0){break_1$=0;
switch_1=0;
nm_7$=a->ntyp;
if ((nm_7$==TRUE) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
}
;
if ((nm_7$==FALSE) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
return_1=1;
RValue=1;
}
;
if ((nm_7$==PREDICATE) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
if ((!(a->sym)) || (!(b->sym))){fatal(0,"sameform...",NULL);
}
;
return_1=1;
RValue=!(strcmp(a->sym->name,b->sym->name));
}
;
if ((nm_7$==NOT) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
return_1=1;
RValue=sameform(0,a->lft,b->lft);
}
;
if ((nm_7$==U_OPER) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
}
;
if ((nm_7$==V_OPER) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
if (!(sameform(1,a->lft,b->lft))){return_1=1;
RValue=0;
}
;
if (return_1==0){if (!(sameform(1,a->rgt,b->rgt))){return_1=1;
RValue=0;
}
;
if (return_1==0){return_1=1;
RValue=1;
}
;
}
;
}
;
if ((nm_7$==AND_1) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
}
;
if ((nm_7$==OR_1) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
return_1=1;
RValue=sametrees(0,a->ntyp,a,b);
}
;
if ((break_1$==0) && (return_1==0)){printf("type: ");
;
printf("\n");
fatal(0,"cannot happen, sameform",NULL);
}
;
if (return_1==0){return_1=1;
RValue=0;
}
;
}
;
}
;
}
;
}
;
return RValue;
}
int  isequal(int $$Ext,Node* a,Node* b){
int  RValue=0;
int return_1;
return_1=0;
if ((!a) && (!b)){return_1=1;
RValue=1;
}
;
if (return_1==0){if ((!a) || (!b)){if (!a){if (b->ntyp==TRUE){return_1=1;
RValue=1;
}
;
} else {if (a->ntyp==TRUE){return_1=1;
RValue=1;
}
;
}
;
if (return_1==0){return_1=1;
RValue=0;
}
;
}
;
if (return_1==0){if (return_1==0){if ((a->ntyp)!=(b->ntyp)){return_1=1;
RValue=0;
}
;
if (return_1==0){if (((a->sym) && (b->sym)) && ((strcmp(a->sym->name,b->sym->name))!=(0))){return_1=1;
RValue=0;
}
;
if (return_1==0){if ((isequal(1,a->lft,b->lft)) && (isequal(1,a->rgt,b->rgt))){return_1=1;
RValue=1;
}
;
if (return_1==0){return_1=1;
RValue=sameform(0,a,b);
}
;
}
;
}
;
}
;
}
;
}
;
return RValue;
}
int  ismatch(int $$Ext,Node* a,Node* b){
int  RValue=0;
int return_1;
return_1=0;
if ((!a) && (!b)){return_1=1;
RValue=1;
}
;
if (return_1==0){if ((!a) || (!b)){return_1=1;
RValue=0;
}
;
if (return_1==0){if ((a->ntyp)!=(b->ntyp)){return_1=1;
RValue=0;
}
;
if (return_1==0){if (((a->sym) && (b->sym)) && ((strcmp(a->sym->name,b->sym->name))!=(0))){return_1=1;
RValue=0;
}
;
if (return_1==0){if ((ismatch(1,a->lft,b->lft)) && (ismatch(1,a->rgt,b->rgt))){return_1=1;
RValue=1;
}
;
if (return_1==0){return_1=1;
RValue=0;
}
;
}
;
}
;
}
;
}
;
return RValue;
}
int  any_term(int $$Ext,Node* srch,Node* in){
int  RValue=0;
int return_1;
return_1=0;
if (!in){return_1=1;
RValue=0;
}
;
if (return_1==0){if (in->ntyp==AND_1){return_1=1;
RValue=(any_term(0,srch,in->lft)) || (any_term(0,srch,in->rgt));
}
;
if (return_1==0){return_1=1;
RValue=isequal(0,in,srch);
}
;
}
;
return RValue;
}
int  any_and(int $$Ext,Node* srch,Node* in){
int  RValue=0;
int return_1;
return_1=0;
if (!in){return_1=1;
RValue=0;
}
;
if (return_1==0){if (srch->ntyp==AND_1){return_1=1;
RValue=(any_and(1,srch->lft,in)) && (any_and(1,srch->rgt,in));
}
;
if (return_1==0){return_1=1;
RValue=any_term(0,srch,in);
}
;
}
;
return RValue;
}
int  any_lor(int $$Ext,Node* srch,Node* in){
int  RValue=0;
int return_1;
return_1=0;
if (!in){return_1=1;
RValue=0;
}
;
if (return_1==0){if (in->ntyp==OR_1){return_1=1;
RValue=(any_lor(0,srch,in->lft)) || (any_lor(0,srch,in->rgt));
}
;
if (return_1==0){return_1=1;
RValue=isequal(0,in,srch);
}
;
}
;
return RValue;
}
int  anywhere(int $$Ext,int tok,Node* srch,Node* in){
int  RValue=0;
int return_1;
int switch_1;
int break_1$;
int nm_8$;
return_1=0;
if (!in){return_1=1;
RValue=0;
}
;
if (return_1==0){break_1$=0;
switch_1=0;
nm_8$=tok;
if ((nm_8$==AND_1) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
return_1=1;
RValue=any_and(0,srch,in);
}
;
if ((nm_8$==OR_1) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
return_1=1;
RValue=any_lor(0,srch,in);
}
;
if ((nm_8$==0) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
return_1=1;
RValue=any_term(0,srch,in);
}
;
if (return_1==0){fatal(0,"cannot happen, anywhere",NULL);
return_1=1;
RValue=0;
}
;
}
;
return RValue;
}
void  free_gstate(int $$Ext,GState* s){
free_gtrans(0,s->trans->nxt,s->trans,1);
tfree(0,s->nodes_set);
tfree(0,s);
}
GState*  remove_gstate(int $$Ext,GState* s,GState* s1){
GState*  RValue=0;
int return_1;
struct GState *remove_gstate_prv;
return_1=0;
remove_gstate_prv=s->prv;
s->prv->nxt=s->nxt;
s->nxt->prv=s->prv;
free_gtrans(0,s->trans->nxt,s->trans,0);
s->trans=NULL;
tfree(0,s->nodes_set);
s->nodes_set=0;
s->nxt=gremoved->nxt;
gremoved->nxt=s;
s->prv=s1;
s1=gremoved->nxt;
while((s1)!=(gremoved)){if (s1->prv==s){s1->prv=s->prv;
}
;
s1=s1->nxt;
}
;
return_1=1;
RValue=remove_gstate_prv;
return RValue;
}
void  copy_gtrans(int $$Ext,GTrans* from,GTrans* to){
to->to=from->to;
copy_set(0,from->pos,to->pos,1);
copy_set(0,from->neg,to->neg,1);
copy_set(0,from->final,to->final,0);
}
int  same_gtrans(int $$Ext,GState* a,GTrans* s,GState* b,GTrans* t,int use_scc){
int  RValue=0;
int return_1;
return_1=0;
if ((((s->to)!=(t->to)) || (!(same_sets(1,s->pos,t->pos,1)))) || (!(same_sets(1,s->neg,t->neg,1)))){return_1=1;
RValue=0;
}
;
if (return_1==0){if (same_sets(1,s->final,t->final,0)){return_1=1;
RValue=1;
}
;
if (return_1==0){if ((use_scc) && ((((in_set(1,bad_scc,a->incoming)) || (in_set(1,bad_scc,b->incoming))) || ((a->incoming)!=(s->to->incoming))) || ((b->incoming)!=(t->to->incoming)))){return_1=1;
RValue=1;
}
;
if (return_1==0){return_1=1;
RValue=0;
if (!use_scc){return_1=1;
RValue=0;
}
;
if (return_1==0){if ((a->incoming==b->incoming) && (a->incoming==s->to->incoming)){return_1=1;
RValue=0;
}
;
if (return_1==0){return_1=1;
RValue=1;
}
;
}
;
}
;
}
;
}
;
return RValue;
}
int  simplify_gtrans(int $$Ext){
int  RValue=0;
int return_1;
int simplify_gtrans_changed;
struct GState *simplify_gtrans_s;
struct GTrans *simplify_gtrans_t,*simplify_gtrans_t1;
struct GTrans *simplify_gtrans_1_3_free;
return_1=0;
simplify_gtrans_changed=0;
simplify_gtrans_s=gstates->nxt;
while((simplify_gtrans_s)!=(gstates)){simplify_gtrans_t=simplify_gtrans_s->trans->nxt;
while((simplify_gtrans_t)!=(simplify_gtrans_s->trans)){copy_gtrans(0,simplify_gtrans_t,simplify_gtrans_s->trans);
simplify_gtrans_t1=simplify_gtrans_s->trans->nxt;
while(!((((((simplify_gtrans_t)!=(simplify_gtrans_t1)) && (simplify_gtrans_t1->to==simplify_gtrans_t->to)) && (included_set(1,simplify_gtrans_t1->pos,simplify_gtrans_t->pos,1))) && (included_set(1,simplify_gtrans_t1->neg,simplify_gtrans_t->neg,1))) && ((included_set(1,simplify_gtrans_t->final,simplify_gtrans_t1->final,0)) || ((tl_simp_scc) && (((simplify_gtrans_s->incoming)!=(simplify_gtrans_t->to->incoming)) || (in_set(1,bad_scc,simplify_gtrans_s->incoming))))))){simplify_gtrans_t1=simplify_gtrans_t1->nxt;
}
;
if ((simplify_gtrans_t1)!=(simplify_gtrans_s->trans)){simplify_gtrans_1_3_free=simplify_gtrans_t->nxt;
simplify_gtrans_t->to=simplify_gtrans_1_3_free->to;
copy_set(0,simplify_gtrans_1_3_free->pos,simplify_gtrans_t->pos,1);
copy_set(0,simplify_gtrans_1_3_free->neg,simplify_gtrans_t->neg,1);
copy_set(0,simplify_gtrans_1_3_free->final,simplify_gtrans_t->final,0);
simplify_gtrans_t->nxt=simplify_gtrans_1_3_free->nxt;
if (simplify_gtrans_1_3_free==simplify_gtrans_s->trans){simplify_gtrans_s->trans=simplify_gtrans_t;
}
;
free_gtrans(0,simplify_gtrans_1_3_free,0,0);
simplify_gtrans_changed=(simplify_gtrans_changed)+(1);
} else {simplify_gtrans_t=simplify_gtrans_t->nxt;
}
;
}
;
simplify_gtrans_s=simplify_gtrans_s->nxt;
}
;
return_1=1;
RValue=simplify_gtrans_changed;
return RValue;
}
void  retarget_all_gtrans(int $$Ext){
struct GState *retarget_all_gtrans_s;
struct GTrans *retarget_all_gtrans_t;
int retarget_all_gtrans_i;
struct GTrans *retarget_all_gtrans_3_4_5_6_free;
retarget_all_gtrans_i=0;
while(retarget_all_gtrans_i<init_size){if ((init[retarget_all_gtrans_i]) && (!(init[retarget_all_gtrans_i]->trans))){init[retarget_all_gtrans_i]=init[retarget_all_gtrans_i]->prv;
}
;
retarget_all_gtrans_i=(retarget_all_gtrans_i)+(1);
}
;
retarget_all_gtrans_s=gstates->nxt;
while((retarget_all_gtrans_s)!=(gstates)){retarget_all_gtrans_t=retarget_all_gtrans_s->trans->nxt;
while((retarget_all_gtrans_t)!=(retarget_all_gtrans_s->trans)){if (!(retarget_all_gtrans_t->to->trans)){retarget_all_gtrans_t->to=retarget_all_gtrans_t->to->prv;
if (!(retarget_all_gtrans_t->to)){retarget_all_gtrans_3_4_5_6_free=retarget_all_gtrans_t->nxt;
retarget_all_gtrans_t->to=retarget_all_gtrans_3_4_5_6_free->to;
copy_set(0,retarget_all_gtrans_3_4_5_6_free->pos,retarget_all_gtrans_t->pos,1);
copy_set(0,retarget_all_gtrans_3_4_5_6_free->neg,retarget_all_gtrans_t->neg,1);
copy_set(0,retarget_all_gtrans_3_4_5_6_free->final,retarget_all_gtrans_t->final,0);
retarget_all_gtrans_t->nxt=retarget_all_gtrans_3_4_5_6_free->nxt;
if (retarget_all_gtrans_3_4_5_6_free==retarget_all_gtrans_s->trans){retarget_all_gtrans_s->trans=retarget_all_gtrans_t;
}
;
free_gtrans(0,retarget_all_gtrans_3_4_5_6_free,0,0);
} else {retarget_all_gtrans_t=retarget_all_gtrans_t->nxt;
}
;
} else {retarget_all_gtrans_t=retarget_all_gtrans_t->nxt;
}
;
}
;
retarget_all_gtrans_s=retarget_all_gtrans_s->nxt;
}
;
while((gremoved->nxt)!=(gremoved)){retarget_all_gtrans_s=gremoved->nxt;
gremoved->nxt=gremoved->nxt->nxt;
if (retarget_all_gtrans_s->nodes_set){tfree(0,retarget_all_gtrans_s->nodes_set);
}
;
tfree(0,retarget_all_gtrans_s);
}
;
}
int  all_gtrans_match(int $$Ext,GState* a,GState* b,int use_scc){
int  RValue=0;
int return_1;
struct GTrans *all_gtrans_match_s,*all_gtrans_match_t;
return_1=0;
all_gtrans_match_s=a->trans->nxt;
while((return_1==0) && ((all_gtrans_match_s)!=(a->trans))){copy_gtrans(0,all_gtrans_match_s,b->trans);
all_gtrans_match_t=b->trans->nxt;
while(!(same_gtrans(1,a,all_gtrans_match_s,b,all_gtrans_match_t,use_scc))){all_gtrans_match_t=all_gtrans_match_t->nxt;
}
;
if (all_gtrans_match_t==b->trans){return_1=1;
RValue=0;
}
;
if (return_1==0){all_gtrans_match_s=all_gtrans_match_s->nxt;
}
;
}
;
if (return_1==0){all_gtrans_match_t=b->trans->nxt;
while((return_1==0) && ((all_gtrans_match_t)!=(b->trans))){copy_gtrans(0,all_gtrans_match_t,a->trans);
all_gtrans_match_s=a->trans->nxt;
while(!(same_gtrans(1,a,all_gtrans_match_s,b,all_gtrans_match_t,use_scc))){all_gtrans_match_s=all_gtrans_match_s->nxt;
}
;
if (all_gtrans_match_s==a->trans){return_1=1;
RValue=0;
}
;
if (return_1==0){all_gtrans_match_t=all_gtrans_match_t->nxt;
}
;
}
;
if (return_1==0){return_1=1;
RValue=1;
}
;
}
;
return RValue;
}
int  simplify_gstates(int $$Ext){
int  RValue=0;
int continue_1;
int return_1;
int simplify_gstates_changed;
struct GState *simplify_gstates_a,*simplify_gstates_b;
continue_1=0;
return_1=0;
simplify_gstates_changed=0;
continue_1=0;
simplify_gstates_a=gstates->nxt;
while((simplify_gstates_a)!=(gstates)){continue_1=0;
if (simplify_gstates_a->trans==simplify_gstates_a->trans->nxt){simplify_gstates_a=remove_gstate(0,simplify_gstates_a,NULL);
simplify_gstates_changed=(simplify_gstates_changed)+(1);
continue_1=1;
simplify_gstates_a=simplify_gstates_a->nxt;
}
;
if (continue_1==0){gstates->trans=simplify_gstates_a->trans;
simplify_gstates_b=simplify_gstates_a->nxt;
while(!(all_gtrans_match(1,simplify_gstates_a,simplify_gstates_b,tl_simp_scc))){simplify_gstates_b=simplify_gstates_b->nxt;
}
;
if ((simplify_gstates_b)!=(gstates)){if (simplify_gstates_a->incoming>simplify_gstates_b->incoming){simplify_gstates_a=remove_gstate(0,simplify_gstates_a,simplify_gstates_b);
} else {remove_gstate(0,simplify_gstates_b,simplify_gstates_a);
}
;
simplify_gstates_changed=(simplify_gstates_changed)+(1);
}
;
simplify_gstates_a=simplify_gstates_a->nxt;
}
;
}
;
continue_1=0;
retarget_all_gtrans(0);
return_1=1;
RValue=simplify_gstates_changed;
return RValue;
}
int  gdfs(int $$Ext,GState* s){
int  RValue=0;
int break_1;
int return_1;
struct GTrans *gdfs_t;
struct GScc *gdfs_c;
struct GScc *gdfs_scc;
int gdfs_1_result;
break_1=0;
return_1=0;
gdfs_scc=(GScc*)(tl_emalloc(1,16));
gdfs_scc->gstate=s;
gdfs_scc->rank=rank;
gdfs_scc->theta=rank;
rank=(rank)+(1);
gdfs_scc->nxt=scc_stack;
scc_stack=gdfs_scc;
s->incoming=1;
gdfs_t=s->trans->nxt;
while((gdfs_t)!=(s->trans)){if (gdfs_t->to->incoming==0){gdfs_1_result=gdfs(0,gdfs_t->to);
gdfs_scc->theta=((gdfs_scc->theta<gdfs_1_result) ?gdfs_scc->theta : gdfs_1_result );
} else {break_1=0;
gdfs_c=scc_stack->nxt;
while((break_1==0) && ((gdfs_c)!=(0))){if (gdfs_c->gstate==gdfs_t->to){gdfs_scc->theta=((gdfs_scc->theta<gdfs_c->rank) ?gdfs_scc->theta : gdfs_c->rank );
break_1=1;
}
;
if (break_1==0){gdfs_c=gdfs_c->nxt;
}
;
}
;
break_1=0;
}
;
gdfs_t=gdfs_t->nxt;
}
;
if (gdfs_scc->rank==gdfs_scc->theta){while((scc_stack)!=(gdfs_scc)){scc_stack->gstate->incoming=scc_id;
scc_stack=scc_stack->nxt;
}
;
gdfs_scc->gstate->incoming=scc_id;
scc_id=(scc_id)+(1);
scc_stack=gdfs_scc->nxt;
}
;
return_1=1;
RValue=gdfs_scc->theta;
return RValue;
}
void  simplify_gscc(int $$Ext){
int return_1;
struct GState *simplify_gscc_s;
struct GTrans *simplify_gscc_t;
int simplify_gscc_i,**simplify_gscc_scc_final;
return_1=0;
rank=1;
scc_stack=0;
scc_id=1;
if (gstates==gstates->nxt){return_1=1;
}
;
if (return_1==0){simplify_gscc_s=gstates->nxt;
while((simplify_gscc_s)!=(gstates)){simplify_gscc_s->incoming=0;
simplify_gscc_s=simplify_gscc_s->nxt;
}
;
simplify_gscc_i=0;
while(simplify_gscc_i<init_size){if ((init[simplify_gscc_i]) && (init[simplify_gscc_i]->incoming==0)){gdfs(0,init[simplify_gscc_i]);
}
;
simplify_gscc_i=(simplify_gscc_i)+(1);
}
;
simplify_gscc_scc_final=(int**)(tl_emalloc(1,(scc_id*4)));
simplify_gscc_i=0;
while(simplify_gscc_i<scc_id){simplify_gscc_scc_final[simplify_gscc_i]=make_set(0,-1,0);
simplify_gscc_i=(simplify_gscc_i)+(1);
}
;
simplify_gscc_s=gstates->nxt;
while((simplify_gscc_s)!=(gstates)){if (simplify_gscc_s->incoming==0){simplify_gscc_s=remove_gstate(0,simplify_gscc_s,0);
} else {simplify_gscc_t=simplify_gscc_s->trans->nxt;
while((simplify_gscc_t)!=(simplify_gscc_s->trans)){if (simplify_gscc_t->to->incoming==simplify_gscc_s->incoming){merge_sets(0,simplify_gscc_scc_final[simplify_gscc_s->incoming],simplify_gscc_t->final,0);
}
;
simplify_gscc_t=simplify_gscc_t->nxt;
}
;
}
;
simplify_gscc_s=simplify_gscc_s->nxt;
}
;
scc_size=((((scc_id)+(1))/ (8*4)))+(1);
bad_scc=make_set(0,-1,2);
simplify_gscc_i=0;
while(simplify_gscc_i<scc_id){if (!(included_set(1,final_set,simplify_gscc_scc_final[simplify_gscc_i],0))){add_set(0,bad_scc,simplify_gscc_i);
}
;
simplify_gscc_i=(simplify_gscc_i)+(1);
}
;
simplify_gscc_i=0;
while(simplify_gscc_i<scc_id){tfree(0,simplify_gscc_scc_final[simplify_gscc_i]);
simplify_gscc_i=(simplify_gscc_i)+(1);
}
;
tfree(0,simplify_gscc_scc_final);
}
;
}
int  is_final(int $$Ext,int *from,ATrans* at,int i){
int  RValue=0;
int return_1;
struct ATrans *is_final_t;
int is_final_in_to;
return_1=0;
if (((tl_fjtofj) && (!(in_set(1,at->to,i)))) || ((!tl_fjtofj) && (!(in_set(1,from,i))))){return_1=1;
RValue=1;
}
;
if (return_1==0){is_final_in_to=in_set(0,at->to,i);
rem_set(0,at->to,i);
is_final_t=transition[i];
while((return_1==0) && (is_final_t)){if (((included_set(1,is_final_t->to,at->to,0)) && (included_set(1,is_final_t->pos,at->pos,1))) && (included_set(1,is_final_t->neg,at->neg,1))){if (is_final_in_to){add_set(0,at->to,i);
}
;
return_1=1;
RValue=1;
}
;
if (return_1==0){is_final_t=is_final_t->nxt;
}
;
}
;
if (return_1==0){if (is_final_in_to){add_set(0,at->to,i);
}
;
return_1=1;
RValue=0;
}
;
}
;
return RValue;
}
GState*  find_gstate(int $$Ext,int *set,GState* s){
GState*  RValue=0;
int return_1;
return_1=0;
if (same_sets(1,set,s->nodes_set,0)){return_1=1;
RValue=s;
}
;
if (return_1==0){s=gstack->nxt;
gstack->nodes_set=set;
while(!(same_sets(1,set,s->nodes_set,0))){s=s->nxt;
}
;
if ((s)!=(gstack)){return_1=1;
RValue=s;
}
;
if (return_1==0){s=gstates->nxt;
gstates->nodes_set=set;
while(!(same_sets(1,set,s->nodes_set,0))){s=s->nxt;
}
;
if ((s)!=(gstates)){return_1=1;
RValue=s;
}
;
if (return_1==0){s=gremoved->nxt;
gremoved->nodes_set=set;
while(!(same_sets(1,set,s->nodes_set,0))){s=s->nxt;
}
;
if ((s)!=(gremoved)){return_1=1;
RValue=s;
}
;
if (return_1==0){s=(GState*)(tl_emalloc(1,24));
s->id=((empty_set(1,set,0)) ?0 : gstate_id );
if (!(empty_set(1,set,0))){gstate_id=(gstate_id)+(1);
}
;
s->incoming=0;
s->nodes_set=dup_set(0,set,0);
s->trans=emalloc_gtrans(0);
s->trans->nxt=s->trans;
s->nxt=gstack->nxt;
gstack->nxt=s;
return_1=1;
RValue=s;
}
;
}
;
}
;
}
;
return RValue;
}
void  make_gtrans(int $$Ext,GState* s){
int break_1;
int return_1;
int make_gtrans_i,*make_gtrans_list$,make_gtrans_state_trans,make_gtrans_trans_exist;
struct GState *make_gtrans_s1;
struct GTrans *make_gtrans_t;
struct ATrans *make_gtrans_t1,*make_gtrans_free;
struct AProd *make_gtrans_prod;
struct AProd *make_gtrans_p;
struct AProd *make_gtrans_2_p;
struct GTrans *make_gtrans_2_3_trans,*make_gtrans_2_3_t2;
struct GTrans *make_gtrans_2_3_5_free;
struct AProd *make_gtrans_15_p;
break_1=0;
return_1=0;
make_gtrans_state_trans=0;
make_gtrans_trans_exist=1;
make_gtrans_prod=(AProd*)(tl_emalloc(1,20));
make_gtrans_prod->nxt=make_gtrans_prod;
make_gtrans_prod->prv=make_gtrans_prod;
make_gtrans_prod->prod=emalloc_atrans(0);
clear_set(0,make_gtrans_prod->prod->to,0);
clear_set(0,make_gtrans_prod->prod->pos,1);
clear_set(0,make_gtrans_prod->prod->neg,1);
make_gtrans_prod->trans=make_gtrans_prod->prod;
make_gtrans_prod->trans->nxt=make_gtrans_prod->prod;
make_gtrans_list$=list_set(0,s->nodes_set,0);
make_gtrans_i=1;
while(make_gtrans_i<make_gtrans_list$[0]){make_gtrans_p=(AProd*)(tl_emalloc(1,20));
make_gtrans_p->astate=make_gtrans_list$[make_gtrans_i];
make_gtrans_p->trans=transition[make_gtrans_list$[make_gtrans_i]];
if (!(make_gtrans_p->trans)){make_gtrans_trans_exist=0;
}
;
make_gtrans_p->prod=merge_trans(0,make_gtrans_prod->nxt->prod,make_gtrans_p->trans);
make_gtrans_p->nxt=make_gtrans_prod->nxt;
make_gtrans_p->prv=make_gtrans_prod;
make_gtrans_p->nxt->prv=make_gtrans_p;
make_gtrans_p->prv->nxt=make_gtrans_p;
make_gtrans_i=(make_gtrans_i)+(1);
}
;
break_1=0;
while((break_1==0) && (make_gtrans_trans_exist)){make_gtrans_2_p=make_gtrans_prod->nxt;
make_gtrans_t1=make_gtrans_2_p->prod;
if (make_gtrans_t1){clear_set(0,fin$,0);
make_gtrans_i=1;
while(make_gtrans_i<final[0]){if (is_final(1,s->nodes_set,make_gtrans_t1,final[make_gtrans_i])){add_set(0,fin$,final[make_gtrans_i]);
}
;
make_gtrans_i=(make_gtrans_i)+(1);
}
;
break_1=0;
make_gtrans_2_3_t2=s->trans->nxt;
while((break_1==0) && ((make_gtrans_2_3_t2)!=(s->trans))){if (((((tl_simp_fly) && (included_set(1,make_gtrans_t1->to,make_gtrans_2_3_t2->to->nodes_set,0))) && (included_set(1,make_gtrans_t1->pos,make_gtrans_2_3_t2->pos,1))) && (included_set(1,make_gtrans_t1->neg,make_gtrans_2_3_t2->neg,1))) && (same_sets(1,fin$,make_gtrans_2_3_t2->final,0))){make_gtrans_2_3_5_free=make_gtrans_2_3_t2->nxt;
make_gtrans_2_3_t2->to->incoming=(make_gtrans_2_3_t2->to->incoming)-(1);
make_gtrans_2_3_t2->to=make_gtrans_2_3_5_free->to;
copy_set(0,make_gtrans_2_3_5_free->pos,make_gtrans_2_3_t2->pos,1);
copy_set(0,make_gtrans_2_3_5_free->neg,make_gtrans_2_3_t2->neg,1);
copy_set(0,make_gtrans_2_3_5_free->final,make_gtrans_2_3_t2->final,0);
make_gtrans_2_3_t2->nxt=make_gtrans_2_3_5_free->nxt;
if (make_gtrans_2_3_5_free==s->trans){s->trans=make_gtrans_2_3_t2;
}
;
free_gtrans(0,make_gtrans_2_3_5_free,0,0);
make_gtrans_state_trans=(make_gtrans_state_trans)-(1);
} else {if (((((tl_simp_fly) && (included_set(1,make_gtrans_2_3_t2->to->nodes_set,make_gtrans_t1->to,0))) && (included_set(1,make_gtrans_2_3_t2->pos,make_gtrans_t1->pos,1))) && (included_set(1,make_gtrans_2_3_t2->neg,make_gtrans_t1->neg,1))) && (same_sets(1,make_gtrans_2_3_t2->final,fin$,0))){break_1=1;
} else {make_gtrans_2_3_t2=make_gtrans_2_3_t2->nxt;
}
;
}
;
}
;
break_1=0;
if (make_gtrans_2_3_t2==s->trans){make_gtrans_2_3_trans=emalloc_gtrans(0);
make_gtrans_2_3_trans->to=find_gstate(0,make_gtrans_t1->to,s);
make_gtrans_2_3_trans->to->incoming=(make_gtrans_2_3_trans->to->incoming)+(1);
copy_set(0,make_gtrans_t1->pos,make_gtrans_2_3_trans->pos,1);
copy_set(0,make_gtrans_t1->neg,make_gtrans_2_3_trans->neg,1);
copy_set(0,fin$,make_gtrans_2_3_trans->final,0);
make_gtrans_2_3_trans->nxt=s->trans->nxt;
s->trans->nxt=make_gtrans_2_3_trans;
make_gtrans_state_trans=(make_gtrans_state_trans)+(1);
}
;
}
;
if (!(make_gtrans_2_p->trans)){break_1=1;
}
;
if (break_1==0){while(!(make_gtrans_2_p->trans->nxt)){make_gtrans_2_p=make_gtrans_2_p->nxt;
}
;
if (make_gtrans_2_p==make_gtrans_prod){break_1=1;
}
;
if (break_1==0){make_gtrans_2_p->trans=make_gtrans_2_p->trans->nxt;
do_merge_trans(0,&make_gtrans_2_p->prod,make_gtrans_2_p->nxt->prod,make_gtrans_2_p->trans);
make_gtrans_2_p=make_gtrans_2_p->prv;
while((make_gtrans_2_p)!=(make_gtrans_prod)){make_gtrans_2_p->trans=transition[make_gtrans_2_p->astate];
do_merge_trans(0,&make_gtrans_2_p->prod,make_gtrans_2_p->nxt->prod,make_gtrans_2_p->trans);
make_gtrans_2_p=make_gtrans_2_p->prv;
}
;
}
;
}
;
}
;
break_1=0;
tfree(0,make_gtrans_list$);
while((make_gtrans_prod->nxt)!=(make_gtrans_prod)){make_gtrans_15_p=make_gtrans_prod->nxt;
make_gtrans_prod->nxt=make_gtrans_15_p->nxt;
free_atrans(0,make_gtrans_15_p->prod,0);
tfree(0,make_gtrans_15_p);
}
;
free_atrans(0,make_gtrans_prod->prod,0);
tfree(0,make_gtrans_prod);
if (tl_simp_fly){if (s->trans==s->trans->nxt){free_gtrans(0,s->trans->nxt,s->trans,1);
s->trans=NULL;
s->prv=NULL;
s->nxt=gremoved->nxt;
gremoved->nxt=s;
make_gtrans_s1=gremoved->nxt;
while((make_gtrans_s1)!=(gremoved)){if (make_gtrans_s1->prv==s){make_gtrans_s1->prv=NULL;
}
;
make_gtrans_s1=make_gtrans_s1->nxt;
}
;
return_1=1;
}
;
if (return_1==0){gstates->trans=s->trans;
make_gtrans_s1=gstates->nxt;
while(!(all_gtrans_match(1,s,make_gtrans_s1,0))){make_gtrans_s1=make_gtrans_s1->nxt;
}
;
if ((make_gtrans_s1)!=(gstates)){free_gtrans(0,s->trans->nxt,s->trans,1);
s->trans=NULL;
s->prv=make_gtrans_s1;
s->nxt=gremoved->nxt;
gremoved->nxt=s;
make_gtrans_s1=gremoved->nxt;
while((make_gtrans_s1)!=(gremoved)){if (make_gtrans_s1->prv==s){make_gtrans_s1->prv=s->prv;
}
;
make_gtrans_s1=make_gtrans_s1->nxt;
}
;
return_1=1;
}
;
}
;
}
;
if (return_1==0){s->nxt=gstates->nxt;
s->prv=gstates;
s->nxt->prv=s;
gstates->nxt=s;
gtrans_count=(gtrans_count)+(make_gtrans_state_trans);
gstate_count=(gstate_count)+(1);
}
;
}
void  reverse_print_generalized(int $$Ext,GState* s){
int return_1;
struct GTrans *reverse_print_generalized_t;
return_1=0;
if (s==gstates){return_1=1;
}
;
if (return_1==0){reverse_print_generalized(0,s->nxt);
printf("state ");
;
printf("i (");
print_set(0,s->nodes_set,0);
printf(") : ");
;
printf("i\n");
reverse_print_generalized_t=s->trans->nxt;
while((reverse_print_generalized_t)!=(s->trans)){if ((empty_set(1,reverse_print_generalized_t->pos,1)) && (empty_set(1,reverse_print_generalized_t->neg,1))){printf("1");
}
;
print_set(0,reverse_print_generalized_t->pos,1);
if ((!(empty_set(1,reverse_print_generalized_t->pos,1))) && (!(empty_set(1,reverse_print_generalized_t->neg,1)))){printf(" & ");
}
;
print_set(0,reverse_print_generalized_t->neg,1);
printf(" -> ");
;
printf("i : ");
print_set(0,reverse_print_generalized_t->final,0);
printf("\n");
reverse_print_generalized_t=reverse_print_generalized_t->nxt;
}
;
}
;
}
void  print_generalized(int $$Ext){
int print_generalized_i;
printf("init :\n");
print_generalized_i=0;
while(print_generalized_i<init_size){if (init[print_generalized_i]){;
printf("i\n");
printf("i\n");
}
;
print_generalized_i=(print_generalized_i)+(1);
}
;
reverse_print_generalized(0,gstates->nxt);
}
void  mk_generalized(int $$Ext){
int continue_1;
struct ATrans *mk_generalized_t;
struct GState *mk_generalized_s;
int mk_generalized_i;
continue_1=0;
fin$=new_set(0,0);
bad_scc=0;
final=list_set(0,final_set,0);
gstack=(GState*)(tl_emalloc(1,24));
gstack->nxt=gstack;
gremoved=(GState*)(tl_emalloc(1,24));
gremoved->nxt=gremoved;
gstates=(GState*)(tl_emalloc(1,24));
gstates->nxt=gstates;
gstates->prv=gstates;
mk_generalized_t=transition[0];
while(mk_generalized_t){mk_generalized_s=(GState*)(tl_emalloc(1,24));
mk_generalized_s->id=((empty_set(1,mk_generalized_t->to,0)) ?0 : gstate_id );
if (!(empty_set(1,mk_generalized_t->to,0))){gstate_id=(gstate_id)+(1);
}
;
mk_generalized_s->incoming=1;
mk_generalized_s->nodes_set=dup_set(0,mk_generalized_t->to,0);
mk_generalized_s->trans=emalloc_gtrans(0);
mk_generalized_s->trans->nxt=mk_generalized_s->trans;
mk_generalized_s->nxt=gstack->nxt;
gstack->nxt=mk_generalized_s;
init_size=(init_size)+(1);
mk_generalized_t=mk_generalized_t->nxt;
}
;
if (init_size){init=(GState**)(tl_emalloc(1,(init_size*4)));
}
;
init_size=0;
mk_generalized_s=gstack->nxt;
while((mk_generalized_s)!=(gstack)){init[init_size]=mk_generalized_s;
init_size=(init_size)+(1);
mk_generalized_s=mk_generalized_s->nxt;
}
;
while((gstack->nxt)!=(gstack)){continue_1=0;
mk_generalized_s=gstack->nxt;
gstack->nxt=gstack->nxt->nxt;
if (!(mk_generalized_s->incoming)){free_gstate(0,mk_generalized_s);
continue_1=1;
}
;
if (continue_1==0){make_gtrans(0,mk_generalized_s);
}
;
}
;
continue_1=0;
retarget_all_gtrans(0);
tfree(0,gstack);
free_all_atrans(0);
tfree(0,transition);
if (tl_verbose){printf("\nGeneralized Buchi automaton before simplification\n");
print_generalized(0);
}
;
if (tl_simp_diff){if (tl_simp_scc){simplify_gscc(0);
}
;
simplify_gtrans(0);
if (tl_simp_scc){simplify_gscc(0);
}
;
while(simplify_gstates(1)){if (tl_simp_scc){simplify_gscc(0);
}
;
simplify_gtrans(0);
if (tl_simp_scc){simplify_gscc(0);
}
;
}
;
if (tl_verbose){printf("\nGeneralized Buchi automaton after simplification\n");
print_generalized(0);
}
;
}
;
}
int  isalnum_(int $$Ext,int c){
int  RValue=0;
int return_1;
return_1=0;
return_1=1;
RValue=((((c>47) && (c<58)) || ((c>64) && (c<91))) || ((c>96) && (c<123))) || (c=='_');
return RValue;
}
int  hash(int $$Ext,char *s){
int  RValue=0;
int return_1;
int hash_h;
return_1=0;
hash_h=0;
while((*(s))){hash_h=(hash_h)+((*(s)));
s=(s)+(1);
hash_h=(hash_h)<<(1);
if ((hash_h)&((255)+(1))){hash_h=(hash_h)|(1);
}
;
}
;
return_1=1;
RValue=(hash_h)&(255);
return RValue;
}
void  getword(int $$Ext,int first,int (*tst)(int $$Ext,int $$NoCare)){
int getword_i;
char getword_c;
int getword_1_temp$_1;
getword_i=0;
yytext[getword_i]=(char)(first);
getword_i=(getword_i)+(1);
getword_1_temp$_1=tl_Getchar(0);
getword_c=getword_1_temp$_1;
while(tst(1,getword_c)){yytext[getword_i]=getword_c;
getword_i=(getword_i)+(1);
getword_1_temp$_1=tl_Getchar(0);
getword_c=getword_1_temp$_1;
}
;
yytext[getword_i]='\0';
tl_UnGetchar(0);
}
int  follow(int $$Ext,int tok,int ifyes,int ifno){
int  RValue=0;
int return_1;
int follow_c;
char follow_buf[32];
return_1=0;
follow_c=tl_Getchar(0);
if (follow_c==tok){return_1=1;
RValue=ifyes;
}
;
if (return_1==0){tl_UnGetchar(0);
tl_yychar=follow_c;
sprintf(follow_buf,"expected \'%c\'",tok);
tl_yyerror(0,follow_buf);
return_1=1;
RValue=ifno;
}
;
return RValue;
}
int  tl_yylex(int $$Ext){
int  RValue=0;
int return_1;
int tl_yylex_c;
return_1=0;
tl_yylex_c=tl_lex(0);
return_1=1;
RValue=tl_yylex_c;
return RValue;
}
int  tl_lex(int $$Ext){
int  RValue=0;
int return_1;
int tl_lex_c;
int count$;
int switch_1;
int break_1$;
int nm_9$;
return_1=0;
count$=0;
while((return_1==0) && ((count$==0) || (tl_lex_c==' '))){count$=(count$)+(1);
tl_lex_c=tl_Getchar(0);
yytext[0]=(char)(tl_lex_c);
yytext[1]='\0';
if ((tl_lex_c)<=(0)){tl_yylval=tl_nn(0,';',NULL,NULL);
return_1=1;
RValue=';';
}
;
}
;
if (return_1==0){if ((tl_lex_c>96) && (tl_lex_c<123)){getword(0,tl_lex_c,isalnum_);
if (strcmp("true",yytext)==0){tl_yylval=tl_nn(0,TRUE,NULL,NULL);
return_1=1;
RValue=TRUE;
}
;
if (return_1==0){if (strcmp("false",yytext)==0){tl_yylval=tl_nn(0,FALSE,NULL,NULL);
return_1=1;
RValue=FALSE;
}
;
if (return_1==0){tl_yylval=tl_nn(0,PREDICATE,NULL,NULL);
tl_yylval->sym=tl_lookup(0,yytext);
return_1=1;
RValue=PREDICATE;
}
;
}
;
}
;
if (return_1==0){if (return_1==0){if (tl_lex_c=='<'){tl_lex_c=tl_Getchar(0);
if (tl_lex_c=='>'){tl_yylval=tl_nn(0,EVENTUALLY,NULL,NULL);
return_1=1;
RValue=EVENTUALLY;
}
;
if (return_1==0){if ((tl_lex_c)!=('-')){tl_UnGetchar(0);
tl_yyerror(0,"expected \'<>\' or \'<->\'");
}
;
tl_lex_c=tl_Getchar(0);
if (tl_lex_c=='>'){tl_yylval=tl_nn(0,EQUIV,NULL,NULL);
return_1=1;
RValue=EQUIV;
}
;
if (return_1==0){tl_UnGetchar(0);
tl_yyerror(0,"expected \'<->\'");
}
;
}
;
}
;
if (return_1==0){break_1$=0;
switch_1=0;
nm_9$=tl_lex_c;
if ((nm_9$=='/') || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
tl_lex_c=follow(0,'\\',AND_1,'/');
break_1$=1;
}
;
if ((nm_9$=='\\') || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
tl_lex_c=follow(0,'/',OR_1,'\\');
break_1$=1;
}
;
if ((nm_9$=='&') || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
tl_lex_c=follow(0,'&',AND_1,'&');
break_1$=1;
}
;
if ((nm_9$=='|') || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
tl_lex_c=follow(0,'|',OR_1,'|');
break_1$=1;
}
;
if ((nm_9$=='[') || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
tl_lex_c=follow(0,']',ALWAYS,'[');
break_1$=1;
}
;
if ((nm_9$=='-') || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
tl_lex_c=follow(0,'>',IMPLIES,'-');
break_1$=1;
}
;
if ((nm_9$=='!') || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
tl_lex_c=NOT;
break_1$=1;
}
;
if ((nm_9$=='U') || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
tl_lex_c=U_OPER;
break_1$=1;
}
;
if ((nm_9$=='V') || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
tl_lex_c=V_OPER;
break_1$=1;
}
;
if ((break_1$==0) && (return_1==0)){break_1$=1;
}
;
tl_yylval=tl_nn(0,tl_lex_c,NULL,NULL);
return_1=1;
RValue=tl_lex_c;
}
;
}
;
}
;
}
;
return RValue;
}
Symbol*  tl_lookup(int $$Ext,char *s){
Symbol*  RValue=0;
int return_1;
struct Symbol *tl_lookup_sp;
int tl_lookup_h;
int tl_lookup_j;
int tl_lookup_temp$_1;
return_1=0;
tl_lookup_h=hash(0,s);
tl_lookup_j=0;
while(tl_lookup_j<(255)+(1)){symtab[tl_lookup_j]=NULL;
tl_lookup_j=(tl_lookup_j)+(1);
}
;
tl_lookup_sp=symtab[tl_lookup_h];
while((return_1==0) && (tl_lookup_sp)){if (strcmp(tl_lookup_sp->name,s)==0){return_1=1;
RValue=tl_lookup_sp;
}
;
if (return_1==0){tl_lookup_sp=tl_lookup_sp->next$;
}
;
}
;
if (return_1==0){tl_lookup_sp=(Symbol*)(tl_emalloc(1,8));
tl_lookup_temp$_1=strlen(s);
tl_lookup_sp->name=(char *)(tl_emalloc(1,(tl_lookup_temp$_1)+(1)));
strcpy(tl_lookup_sp->name,s);
tl_lookup_sp->next$=symtab[tl_lookup_h];
symtab[tl_lookup_h]=tl_lookup_sp;
return_1=1;
RValue=tl_lookup_sp;
}
;
return RValue;
}
Symbol*  getsym(int $$Ext,Symbol* s){
Symbol*  RValue=0;
int return_1;
struct Symbol *getsym_n;
return_1=0;
getsym_n=(Symbol*)(tl_emalloc(1,8));
getsym_n->name=s->name;
return_1=1;
RValue=getsym_n;
return RValue;
}
void * tl_emalloc(int $$Ext,int U){
void * RValue=0;
int return_1;
void *tl_emalloc_r;
return_1=0;
tl_emalloc_r=(void *)(malloc(U));
memset(tl_emalloc_r,0,U);
return_1=1;
RValue=tl_emalloc_r;
return RValue;
}
void  tfree(int $$Ext,void *v){
int tfree_i;
tfree_i=0;
free(v);
}
ATrans*  emalloc_atrans(int $$Ext){
ATrans*  RValue=0;
int return_1;
struct ATrans *emalloc_atrans_result;
return_1=0;
if (!atrans_list){emalloc_atrans_result=(ATrans*)(tl_emalloc(1,20));
emalloc_atrans_result->pos=new_set(0,1);
emalloc_atrans_result->neg=new_set(0,1);
emalloc_atrans_result->to=new_set(0,0);
apool=(apool)+(1);
} else {emalloc_atrans_result=atrans_list;
atrans_list=atrans_list->nxt;
emalloc_atrans_result->nxt=NULL;
}
;
aallocs=(aallocs)+(1);
return_1=1;
RValue=emalloc_atrans_result;
return RValue;
}
void  free_atrans(int $$Ext,ATrans* t,int rec){
int return_1;
return_1=0;
if (!t){return_1=1;
}
;
if (return_1==0){if (rec){free_atrans(0,t->nxt,rec);
}
;
t->nxt=atrans_list;
atrans_list=t;
afrees=(afrees)+(1);
}
;
}
void  free_all_atrans(int $$Ext){
struct ATrans *free_all_atrans_t;
while(atrans_list){free_all_atrans_t=atrans_list;
atrans_list=free_all_atrans_t->nxt;
tfree(0,free_all_atrans_t->to);
tfree(0,free_all_atrans_t->pos);
tfree(0,free_all_atrans_t->neg);
tfree(0,free_all_atrans_t);
}
;
}
GTrans*  emalloc_gtrans(int $$Ext){
GTrans*  RValue=0;
int return_1;
struct GTrans *emalloc_gtrans_result;
return_1=0;
if (!gtrans_list){emalloc_gtrans_result=(GTrans*)(tl_emalloc(1,20));
emalloc_gtrans_result->pos=new_set(0,1);
emalloc_gtrans_result->neg=new_set(0,1);
emalloc_gtrans_result->final=new_set(0,0);
gpool=(gpool)+(1);
} else {emalloc_gtrans_result=gtrans_list;
gtrans_list=gtrans_list->nxt;
}
;
gallocs=(gallocs)+(1);
return_1=1;
RValue=emalloc_gtrans_result;
return RValue;
}
void  free_gtrans(int $$Ext,GTrans* t,GTrans* sentinel,int fly){
gfrees=(gfrees)+(1);
if ((sentinel) && ((t)!=(sentinel))){free_gtrans(0,t->nxt,sentinel,fly);
if (fly){t->to->incoming=(t->to->incoming)-(1);
}
;
}
;
t->nxt=gtrans_list;
gtrans_list=t;
}
BTrans*  emalloc_btrans(int $$Ext){
BTrans*  RValue=0;
int return_1;
struct BTrans *emalloc_btrans_result;
return_1=0;
if (!btrans_list){emalloc_btrans_result=(BTrans*)(tl_emalloc(1,16));
emalloc_btrans_result->pos=new_set(0,1);
emalloc_btrans_result->neg=new_set(0,1);
bpool=(bpool)+(1);
} else {emalloc_btrans_result=btrans_list;
btrans_list=btrans_list->nxt;
}
;
ballocs=(ballocs)+(1);
return_1=1;
RValue=emalloc_btrans_result;
return RValue;
}
void  free_btrans(int $$Ext,BTrans* t,BTrans* sentinel,int fly){
bfrees=(bfrees)+(1);
if ((sentinel) && ((t)!=(sentinel))){free_btrans(0,t->nxt,sentinel,fly);
if (fly){t->to->incoming=(t->to->incoming)-(1);
}
;
}
;
t->nxt=btrans_list;
btrans_list=t;
}
void  a_stats(int $$Ext){
int a_stats_p,a_stats_a,a_stats_f;
int a_stats_i;
printf(" size\t  pool\tallocs\t frees\n");
a_stats_i=0;
while(a_stats_i<80){a_stats_p=event[0][a_stats_i];
a_stats_a=event[1][a_stats_i];
a_stats_f=event[2][a_stats_i];
if (((a_stats_p)|(a_stats_a))|(a_stats_f)){printf("%d",a_stats_i);
printf("\t");
printf("%d",a_stats_p);
printf("\t");
printf("%d",a_stats_a);
printf("\t");
printf("%d",a_stats_f);
printf("\n");
printf("\n");
}
;
a_stats_i=(a_stats_i)+(1);
}
;
printf("atrans\t");
printf("%d",apool);
printf("\t");
printf("%d",aallocs);
printf("\t");
printf("%d",afrees);
printf("\n");
printf("gtrans\t");
printf("%d",gpool);
printf("\t");
printf("%d",gallocs);
printf("\t");
printf("%d",gfrees);
printf("\n");
printf("btrans\t");
printf("%d",bpool);
printf("\t");
printf("%d",ballocs);
printf("\t");
printf("%d",bfrees);
printf("\n");
}
int  implies(int $$Ext,Node* a,Node* b){
int  RValue=0;
int return_1;
return_1=0;
return_1=1;
RValue=(((((((((((isequal(1,a,b)) || (b->ntyp==TRUE)) || (a->ntyp==FALSE)) || (((b->ntyp==AND_1) && (implies(1,a,b->lft))) && (implies(1,a,b->rgt)))) || (((a->ntyp==OR_1) && (implies(1,a->lft,b))) && (implies(1,a->rgt,b)))) || ((a->ntyp==AND_1) && ((implies(1,a->lft,b)) || (implies(1,a->rgt,b))))) || ((b->ntyp==OR_1) && ((implies(1,a,b->lft)) || (implies(1,a,b->rgt))))) || ((b->ntyp==U_OPER) && (implies(1,a,b->rgt)))) || ((a->ntyp==V_OPER) && (implies(1,a->rgt,b)))) || (((a->ntyp==U_OPER) && (implies(1,a->lft,b))) && (implies(1,a->rgt,b)))) || (((b->ntyp==V_OPER) && (implies(1,a,b->lft))) && (implies(1,a,b->rgt)))) || (((((a->ntyp==U_OPER) || (a->ntyp==V_OPER)) && (a->ntyp==b->ntyp)) && (implies(1,a->lft,b->lft))) && (implies(1,a->rgt,b->rgt)));
return RValue;
}
Node*  bin_simpler(int $$Ext,Node* ptr){
Node*  RValue=0;
int return_1;
struct Node *bin_simpler_a,*bin_simpler_b;
int switch_1;
int break_1$;
int nm_10$;
struct Node *bin_simpler_1_2_8_temp$_1;
struct Node *bin_simpler_1_2_8_temp$_2;
struct Node *bin_simpler_1_2_8_temp$_3;
struct Node *bin_simpler_1_2_14_temp$_4;
struct Node *bin_simpler_1_2_14_temp$_5;
struct Node *bin_simpler_1_2_14_temp$_6;
struct Node *bin_simpler_1_2_temp$_7;
struct Node *bin_simpler_1_2_temp$_8;
struct Node *bin_simpler_1_2_temp$_9;
struct Node *bin_simpler_1_2_temp$_10;
struct Node *bin_simpler_1_2_temp$_11;
struct Node *bin_simpler_1_2_temp$_12;
struct Node *bin_simpler_1_2_temp$_13;
struct Node *bin_simpler_1_2_temp$_14;
struct Node *bin_simpler_1_2_temp$_15;
struct Node *bin_simpler_1_2_temp$_16;
struct Node *bin_simpler_1_2_temp$_17;
struct Node *bin_simpler_1_2_temp$_18;
struct Node *bin_simpler_1_2_temp$_19;
struct Node *bin_simpler_1_2_temp$_20;
struct Node *bin_simpler_1_2_21_temp$_21;
struct Node *bin_simpler_1_2_22_temp$_22;
struct Node *bin_simpler_1_2_26_temp$_23;
struct Node *bin_simpler_1_2_26_temp$_24;
struct Node *bin_simpler_1_2_26_temp$_25;
struct Node *bin_simpler_1_2_26_temp$_26;
struct Node *bin_simpler_1_2_27_temp$_27;
struct Node *bin_simpler_1_2_27_temp$_28;
struct Node *bin_simpler_1_2_27_temp$_29;
struct Node *bin_simpler_1_2_27_temp$_30;
struct Node *bin_simpler_1_2_27_temp$_31;
struct Node *bin_simpler_1_2_27_temp$_32;
struct Node *bin_simpler_1_2_30_temp$_33;
struct Node *bin_simpler_1_2_33_temp$_34;
struct Node *bin_simpler_1_2_35_temp$_35;
struct Node *bin_simpler_1_2_35_temp$_36;
struct Node *bin_simpler_1_2_35_temp$_37;
struct Node *bin_simpler_1_2_35_temp$_38;
struct Node *bin_simpler_1_2_36_temp$_39;
struct Node *bin_simpler_1_2_36_temp$_40;
struct Node *bin_simpler_1_2_36_temp$_41;
struct Node *bin_simpler_1_2_36_temp$_42;
struct Node *bin_simpler_1_2_36_temp$_43;
struct Node *bin_simpler_1_2_36_temp$_44;
return_1=0;
if (ptr){break_1$=0;
switch_1=0;
nm_10$=ptr->ntyp;
if ((nm_10$==U_OPER) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
if (((ptr->rgt->ntyp==TRUE) || (ptr->rgt->ntyp==FALSE)) || (ptr->lft->ntyp==FALSE)){ptr=ptr->rgt;
break_1$=1;
}
;
if (break_1$==0){if (implies(1,ptr->lft,ptr->rgt)){ptr=ptr->rgt;
break_1$=1;
}
;
if (break_1$==0){if ((ptr->lft->ntyp==U_OPER) && (isequal(1,ptr->lft->lft,ptr->rgt))){ptr->lft=ptr->lft->rgt;
break_1$=1;
}
;
if (break_1$==0){if ((ptr->rgt->ntyp==U_OPER) && (implies(1,ptr->lft,ptr->rgt->lft))){ptr=ptr->rgt;
break_1$=1;
}
;
if (break_1$==0){if (((((ptr->lft->ntyp==TRUE) && (ptr->rgt->ntyp==V_OPER)) && (ptr->rgt->lft->ntyp==FALSE)) && (ptr->rgt->rgt->ntyp==U_OPER)) && (ptr->rgt->rgt->lft->ntyp==TRUE)){ptr=ptr->rgt;
break_1$=1;
}
;
if (break_1$==0){bin_simpler_1_2_8_temp$_1=dupnode(0,ptr->rgt);
bin_simpler_1_2_8_temp$_2=tl_nn(0,NOT,bin_simpler_1_2_8_temp$_1,NULL);
bin_simpler_1_2_8_temp$_3=push_negation(0,bin_simpler_1_2_8_temp$_2);
if (((ptr->lft->ntyp)!=(TRUE)) && (implies(1,bin_simpler_1_2_8_temp$_3,ptr->lft))){ptr->lft=tl_nn(0,TRUE,NULL,NULL);
break_1$=1;
}
;
if (break_1$==0){break_1$=1;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
if ((nm_10$==V_OPER) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
if (((ptr->rgt->ntyp==FALSE) || (ptr->rgt->ntyp==TRUE)) || (ptr->lft->ntyp==TRUE)){ptr=ptr->rgt;
break_1$=1;
}
;
if (break_1$==0){if (implies(1,ptr->rgt,ptr->lft)){ptr=ptr->rgt;
break_1$=1;
}
;
if (break_1$==0){if ((ptr->lft->ntyp==FALSE) && (ptr->rgt->ntyp==V_OPER)){ptr->rgt=ptr->rgt->rgt;
break_1$=1;
}
;
if (break_1$==0){if (((((ptr->lft->ntyp==FALSE) && (ptr->rgt->ntyp==U_OPER)) && (ptr->rgt->lft->ntyp==TRUE)) && (ptr->rgt->rgt->ntyp==V_OPER)) && (ptr->rgt->rgt->lft->ntyp==FALSE)){ptr=ptr->rgt;
break_1$=1;
}
;
if (break_1$==0){if ((ptr->rgt->ntyp==V_OPER) && (implies(1,ptr->rgt->lft,ptr->lft))){ptr=ptr->rgt;
break_1$=1;
}
;
if (break_1$==0){bin_simpler_1_2_14_temp$_4=dupnode(0,ptr->rgt);
bin_simpler_1_2_14_temp$_5=tl_nn(0,NOT,bin_simpler_1_2_14_temp$_4,NULL);
bin_simpler_1_2_14_temp$_6=push_negation(0,bin_simpler_1_2_14_temp$_5);
if (((ptr->lft->ntyp)!=(FALSE)) && (implies(1,ptr->lft,bin_simpler_1_2_14_temp$_6))){ptr->lft=tl_nn(0,FALSE,NULL,NULL);
break_1$=1;
}
;
if (break_1$==0){break_1$=1;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
if ((nm_10$==IMPLIES) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
if (implies(1,ptr->lft,ptr->rgt)){ptr=tl_nn(0,TRUE,NULL,NULL);
break_1$=1;
}
;
if (break_1$==0){bin_simpler_1_2_temp$_7=tl_nn(0,NOT,ptr->lft,NULL);
bin_simpler_1_2_temp$_8=push_negation(0,bin_simpler_1_2_temp$_7);
ptr=tl_nn(0,OR_1,bin_simpler_1_2_temp$_8,ptr->rgt);
bin_simpler_1_2_temp$_9=right_linked(0,ptr);
ptr=canonical(0,bin_simpler_1_2_temp$_9);
break_1$=1;
}
;
}
;
if ((nm_10$==EQUIV) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
if ((implies(1,ptr->lft,ptr->rgt)) && (implies(1,ptr->rgt,ptr->lft))){ptr=tl_nn(0,TRUE,NULL,NULL);
break_1$=1;
}
;
if (break_1$==0){bin_simpler_1_2_temp$_10=dupnode(0,ptr->rgt);
bin_simpler_1_2_temp$_11=dupnode(0,ptr->lft);
bin_simpler_1_2_temp$_12=tl_nn(0,AND_1,bin_simpler_1_2_temp$_11,bin_simpler_1_2_temp$_10);
bin_simpler_1_2_temp$_13=right_linked(0,bin_simpler_1_2_temp$_12);
bin_simpler_a=canonical(0,bin_simpler_1_2_temp$_13);
bin_simpler_1_2_temp$_14=tl_nn(0,NOT,ptr->rgt,NULL);
bin_simpler_1_2_temp$_15=push_negation(0,bin_simpler_1_2_temp$_14);
bin_simpler_1_2_temp$_16=tl_nn(0,NOT,ptr->lft,NULL);
bin_simpler_1_2_temp$_17=push_negation(0,bin_simpler_1_2_temp$_16);
bin_simpler_1_2_temp$_18=tl_nn(0,AND_1,bin_simpler_1_2_temp$_17,bin_simpler_1_2_temp$_15);
bin_simpler_1_2_temp$_19=right_linked(0,bin_simpler_1_2_temp$_18);
bin_simpler_b=canonical(0,bin_simpler_1_2_temp$_19);
ptr=tl_nn(0,OR_1,bin_simpler_a,bin_simpler_b);
bin_simpler_1_2_temp$_20=right_linked(0,ptr);
ptr=canonical(0,bin_simpler_1_2_temp$_20);
break_1$=1;
}
;
}
;
if ((nm_10$==AND_1) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
if ((ptr->rgt->ntyp==U_OPER) && (isequal(1,ptr->rgt->rgt,ptr->lft))){ptr=ptr->lft;
break_1$=1;
}
;
if (break_1$==0){if ((ptr->lft->ntyp==U_OPER) && (isequal(1,ptr->lft->rgt,ptr->rgt))){ptr=ptr->rgt;
break_1$=1;
}
;
if (break_1$==0){if ((ptr->rgt->ntyp==V_OPER) && (isequal(1,ptr->rgt->rgt,ptr->lft))){ptr=ptr->rgt;
break_1$=1;
}
;
if (break_1$==0){if ((ptr->lft->ntyp==V_OPER) && (isequal(1,ptr->lft->rgt,ptr->rgt))){ptr=ptr->lft;
break_1$=1;
}
;
if (break_1$==0){if (((ptr->rgt->ntyp==U_OPER) && (ptr->lft->ntyp==U_OPER)) && (isequal(1,ptr->rgt->rgt,ptr->lft->rgt))){bin_simpler_1_2_21_temp$_21=tl_nn(0,AND_1,ptr->lft->lft,ptr->rgt->lft);
ptr=tl_nn(0,U_OPER,bin_simpler_1_2_21_temp$_21,ptr->lft->rgt);
break_1$=1;
}
;
if (break_1$==0){if (((ptr->rgt->ntyp==V_OPER) && (ptr->lft->ntyp==V_OPER)) && (isequal(1,ptr->rgt->lft,ptr->lft->lft))){bin_simpler_1_2_22_temp$_22=tl_nn(0,AND_1,ptr->lft->rgt,ptr->rgt->rgt);
ptr=tl_nn(0,V_OPER,ptr->rgt->lft,bin_simpler_1_2_22_temp$_22);
break_1$=1;
}
;
if (break_1$==0){if (((ptr->rgt->ntyp==U_OPER) && (ptr->lft->ntyp==V_OPER)) && (isequal(1,ptr->lft->rgt,ptr->rgt->rgt))){ptr=ptr->lft;
break_1$=1;
}
;
if (break_1$==0){if ((((isequal(1,ptr->lft,ptr->rgt)) || (ptr->rgt->ntyp==FALSE)) || (ptr->lft->ntyp==TRUE)) || (implies(1,ptr->rgt,ptr->lft))){ptr=ptr->rgt;
break_1$=1;
}
;
if (break_1$==0){if (((ptr->rgt->ntyp==TRUE) || (ptr->lft->ntyp==FALSE)) || (implies(1,ptr->lft,ptr->rgt))){ptr=ptr->lft;
break_1$=1;
}
;
if (break_1$==0){if ((((((((ptr->lft->ntyp==U_OPER) && (ptr->lft->lft->ntyp==TRUE)) && (ptr->lft->rgt->ntyp==V_OPER)) && (ptr->lft->rgt->lft->ntyp==FALSE)) && (ptr->rgt->ntyp==U_OPER)) && (ptr->rgt->lft->ntyp==TRUE)) && (ptr->rgt->rgt->ntyp==V_OPER)) && (ptr->rgt->rgt->lft->ntyp==FALSE)){bin_simpler_1_2_26_temp$_23=tl_nn(0,AND_1,ptr->lft->rgt->rgt,ptr->rgt->rgt->rgt);
bin_simpler_1_2_26_temp$_24=tl_nn(0,FALSE,NULL,NULL);
bin_simpler_1_2_26_temp$_25=tl_nn(0,V_OPER,bin_simpler_1_2_26_temp$_24,bin_simpler_1_2_26_temp$_23);
bin_simpler_1_2_26_temp$_26=tl_nn(0,TRUE,NULL,NULL);
ptr=tl_nn(0,U_OPER,bin_simpler_1_2_26_temp$_26,bin_simpler_1_2_26_temp$_25);
break_1$=1;
}
;
if (break_1$==0){bin_simpler_1_2_27_temp$_27=dupnode(0,ptr->lft);
bin_simpler_1_2_27_temp$_28=tl_nn(0,NOT,bin_simpler_1_2_27_temp$_27,NULL);
bin_simpler_1_2_27_temp$_29=push_negation(0,bin_simpler_1_2_27_temp$_28);
bin_simpler_1_2_27_temp$_30=dupnode(0,ptr->rgt);
bin_simpler_1_2_27_temp$_31=tl_nn(0,NOT,bin_simpler_1_2_27_temp$_30,NULL);
bin_simpler_1_2_27_temp$_32=push_negation(0,bin_simpler_1_2_27_temp$_31);
if ((implies(1,ptr->lft,bin_simpler_1_2_27_temp$_32)) || (implies(1,ptr->rgt,bin_simpler_1_2_27_temp$_29))){ptr=tl_nn(0,FALSE,NULL,NULL);
break_1$=1;
}
;
if (break_1$==0){break_1$=1;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
if ((nm_10$==OR_1) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
if ((ptr->rgt->ntyp==U_OPER) && (isequal(1,ptr->rgt->rgt,ptr->lft))){ptr=ptr->rgt;
break_1$=1;
}
;
if (break_1$==0){if ((ptr->rgt->ntyp==V_OPER) && (isequal(1,ptr->rgt->rgt,ptr->lft))){ptr=ptr->lft;
break_1$=1;
}
;
if (break_1$==0){if (((ptr->rgt->ntyp==U_OPER) && (ptr->lft->ntyp==U_OPER)) && (isequal(1,ptr->rgt->lft,ptr->lft->lft))){bin_simpler_1_2_30_temp$_33=tl_nn(0,OR_1,ptr->lft->rgt,ptr->rgt->rgt);
ptr=tl_nn(0,U_OPER,ptr->rgt->lft,bin_simpler_1_2_30_temp$_33);
break_1$=1;
}
;
if (break_1$==0){if ((((isequal(1,ptr->lft,ptr->rgt)) || (ptr->rgt->ntyp==FALSE)) || (ptr->lft->ntyp==TRUE)) || (implies(1,ptr->rgt,ptr->lft))){ptr=ptr->lft;
break_1$=1;
}
;
if (break_1$==0){if (((ptr->rgt->ntyp==TRUE) || (ptr->lft->ntyp==FALSE)) || (implies(1,ptr->lft,ptr->rgt))){ptr=ptr->rgt;
break_1$=1;
}
;
if (break_1$==0){if (((ptr->rgt->ntyp==V_OPER) && (ptr->lft->ntyp==V_OPER)) && (isequal(1,ptr->lft->rgt,ptr->rgt->rgt))){bin_simpler_1_2_33_temp$_34=tl_nn(0,OR_1,ptr->lft->lft,ptr->rgt->lft);
ptr=tl_nn(0,V_OPER,bin_simpler_1_2_33_temp$_34,ptr->rgt->rgt);
break_1$=1;
}
;
if (break_1$==0){if (((ptr->rgt->ntyp==U_OPER) && (ptr->lft->ntyp==V_OPER)) && (isequal(1,ptr->lft->rgt,ptr->rgt->rgt))){ptr=ptr->rgt;
break_1$=1;
}
;
if (break_1$==0){if ((((((((ptr->lft->ntyp==V_OPER) && (ptr->lft->lft->ntyp==FALSE)) && (ptr->lft->rgt->ntyp==U_OPER)) && (ptr->lft->rgt->lft->ntyp==TRUE)) && (ptr->rgt->ntyp==V_OPER)) && (ptr->rgt->lft->ntyp==FALSE)) && (ptr->rgt->rgt->ntyp==U_OPER)) && (ptr->rgt->rgt->lft->ntyp==TRUE)){bin_simpler_1_2_35_temp$_35=tl_nn(0,OR_1,ptr->lft->rgt->rgt,ptr->rgt->rgt->rgt);
bin_simpler_1_2_35_temp$_36=tl_nn(0,TRUE,NULL,NULL);
bin_simpler_1_2_35_temp$_37=tl_nn(0,U_OPER,bin_simpler_1_2_35_temp$_36,bin_simpler_1_2_35_temp$_35);
bin_simpler_1_2_35_temp$_38=tl_nn(0,FALSE,NULL,NULL);
ptr=tl_nn(0,V_OPER,bin_simpler_1_2_35_temp$_38,bin_simpler_1_2_35_temp$_37);
break_1$=1;
}
;
if (break_1$==0){bin_simpler_1_2_36_temp$_39=dupnode(0,ptr->lft);
bin_simpler_1_2_36_temp$_40=tl_nn(0,NOT,bin_simpler_1_2_36_temp$_39,NULL);
bin_simpler_1_2_36_temp$_41=push_negation(0,bin_simpler_1_2_36_temp$_40);
bin_simpler_1_2_36_temp$_42=dupnode(0,ptr->rgt);
bin_simpler_1_2_36_temp$_43=tl_nn(0,NOT,bin_simpler_1_2_36_temp$_42,NULL);
bin_simpler_1_2_36_temp$_44=push_negation(0,bin_simpler_1_2_36_temp$_43);
if ((implies(1,bin_simpler_1_2_36_temp$_44,ptr->lft)) || (implies(1,bin_simpler_1_2_36_temp$_41,ptr->rgt))){ptr=tl_nn(0,TRUE,NULL,NULL);
break_1$=1;
}
;
if (break_1$==0){break_1$=1;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
}
;
return_1=1;
RValue=ptr;
return RValue;
}
Node*  bin_minimal(int $$Ext,Node* ptr){
Node*  RValue=0;
int return_1;
int switch_1;
int break_1$;
int nm_11$;
struct Node *bin_minimal_1_2_temp$_1;
struct Node *bin_minimal_1_2_temp$_2;
struct Node *bin_minimal_1_2_temp$_3;
struct Node *bin_minimal_1_2_temp$_4;
struct Node *bin_minimal_1_2_temp$_5;
struct Node *bin_minimal_1_2_temp$_6;
struct Node *bin_minimal_1_2_temp$_7;
struct Node *bin_minimal_1_2_temp$_8;
struct Node *bin_minimal_1_2_temp$_9;
struct Node *bin_minimal_1_2_temp$_10;
return_1=0;
if (ptr){break_1$=0;
switch_1=0;
nm_11$=ptr->ntyp;
if ((nm_11$==IMPLIES) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
bin_minimal_1_2_temp$_1=tl_nn(0,NOT,ptr->lft,NULL);
bin_minimal_1_2_temp$_2=push_negation(0,bin_minimal_1_2_temp$_1);
return_1=1;
RValue=tl_nn(0,OR_1,bin_minimal_1_2_temp$_2,ptr->rgt);
}
;
if ((nm_11$==EQUIV) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
bin_minimal_1_2_temp$_3=tl_nn(0,NOT,ptr->rgt,NULL);
bin_minimal_1_2_temp$_4=push_negation(0,bin_minimal_1_2_temp$_3);
bin_minimal_1_2_temp$_5=tl_nn(0,NOT,ptr->lft,NULL);
bin_minimal_1_2_temp$_6=push_negation(0,bin_minimal_1_2_temp$_5);
bin_minimal_1_2_temp$_7=tl_nn(0,AND_1,bin_minimal_1_2_temp$_6,bin_minimal_1_2_temp$_4);
bin_minimal_1_2_temp$_8=dupnode(0,ptr->rgt);
bin_minimal_1_2_temp$_9=dupnode(0,ptr->lft);
bin_minimal_1_2_temp$_10=tl_nn(0,AND_1,bin_minimal_1_2_temp$_9,bin_minimal_1_2_temp$_8);
return_1=1;
RValue=tl_nn(0,OR_1,bin_minimal_1_2_temp$_10,bin_minimal_1_2_temp$_7);
}
;
}
;
if (return_1==0){return_1=1;
RValue=ptr;
}
;
return RValue;
}
Node*  tl_factor(int $$Ext){
Node*  RValue=0;
int return_1;
struct Node *tl_factor_ptr;
int switch_1;
int break_1$;
int nm_12$;
struct Node *tl_factor_1_temp$_1;
struct Node *tl_factor_1_temp$_2;
return_1=0;
tl_factor_ptr=NULL;
break_1$=0;
switch_1=0;
nm_12$=tl_yychar;
if ((nm_12$=='(') || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
tl_factor_ptr=tl_formula(0);
if ((tl_yychar)!=(')')){tl_yyerror(0,"expected \')\'");
}
;
tl_yychar=tl_yylex(0);
if (tl_simp_log){tl_factor_ptr=bin_simpler(0,tl_factor_ptr);
}
;
break_1$=1;
}
;
if ((nm_12$==NOT) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
tl_factor_ptr=tl_yylval;
tl_yychar=tl_yylex(0);
tl_factor_ptr->lft=tl_factor(0);
tl_factor_ptr=push_negation(0,tl_factor_ptr);
if (tl_simp_log){tl_factor_ptr=bin_simpler(0,tl_factor_ptr);
}
;
break_1$=1;
}
;
if ((nm_12$==ALWAYS) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
tl_yychar=tl_yylex(0);
tl_factor_ptr=tl_factor(0);
if (tl_simp_log){if ((tl_factor_ptr->ntyp==FALSE) || (tl_factor_ptr->ntyp==TRUE)){break_1$=1;
}
;
if (break_1$==0){if (tl_factor_ptr->ntyp==V_OPER){if (tl_factor_ptr->lft->ntyp==FALSE){break_1$=1;
}
;
if (break_1$==0){tl_factor_ptr=tl_factor_ptr->rgt;
}
;
}
;
}
;
}
;
if (break_1$==0){tl_factor_1_temp$_1=tl_nn(0,FALSE,NULL,NULL);
tl_factor_ptr=tl_nn(0,V_OPER,tl_factor_1_temp$_1,tl_factor_ptr);
if (tl_simp_log){tl_factor_ptr=bin_simpler(0,tl_factor_ptr);
}
;
break_1$=1;
}
;
}
;
if ((nm_12$==EVENTUALLY) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
tl_yychar=tl_yylex(0);
tl_factor_ptr=tl_factor(0);
if (tl_simp_log){if ((tl_factor_ptr->ntyp==TRUE) || (tl_factor_ptr->ntyp==FALSE)){break_1$=1;
}
;
if (break_1$==0){if ((tl_factor_ptr->ntyp==U_OPER) && (tl_factor_ptr->lft->ntyp==TRUE)){break_1$=1;
}
;
if (break_1$==0){if (tl_factor_ptr->ntyp==U_OPER){tl_factor_ptr=tl_factor_ptr->rgt;
}
;
}
;
}
;
}
;
if (break_1$==0){tl_factor_1_temp$_2=tl_nn(0,TRUE,NULL,NULL);
tl_factor_ptr=tl_nn(0,U_OPER,tl_factor_1_temp$_2,tl_factor_ptr);
if (tl_simp_log){tl_factor_ptr=bin_simpler(0,tl_factor_ptr);
}
;
break_1$=1;
}
;
}
;
if ((nm_12$==PREDICATE) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
tl_factor_ptr=tl_yylval;
tl_yychar=tl_yylex(0);
break_1$=1;
}
;
if ((nm_12$==TRUE) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
}
;
if ((nm_12$==FALSE) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
tl_factor_ptr=tl_yylval;
tl_yychar=tl_yylex(0);
break_1$=1;
}
;
if (!tl_factor_ptr){tl_yyerror(0,"expected predicate");
}
;
return_1=1;
RValue=tl_factor_ptr;
return RValue;
}
Node*  tl_level(int $$Ext,int nr){
Node*  RValue=0;
int return_1;
int tl_level_i;
struct Node *tl_level_ptr;
struct Node *tl_level_2_3_temp$_1;
return_1=0;
tl_level_ptr=NULL;
if (nr<0){return_1=1;
RValue=tl_factor(0);
}
;
if (return_1==0){tl_level_ptr=tl_level(0,(nr)-(1));
tl_level_i=0;
while(tl_level_i<4){if (tl_yychar==prec[nr][tl_level_i]){tl_yychar=tl_yylex(0);
tl_level_2_3_temp$_1=tl_level(0,(nr)-(1));
tl_level_ptr=tl_nn(0,prec[nr][tl_level_i],tl_level_ptr,tl_level_2_3_temp$_1);
if (tl_simp_log){tl_level_ptr=bin_simpler(0,tl_level_ptr);
} else {tl_level_ptr=bin_minimal(0,tl_level_ptr);
}
;
tl_level_i=-1;
}
;
tl_level_i=(tl_level_i)+(1);
}
;
if (!tl_level_ptr){tl_yyerror(0,"syntax error");
}
;
return_1=1;
RValue=tl_level_ptr;
}
;
return RValue;
}
Node*  tl_formula(int $$Ext){
Node*  RValue=0;
int return_1;
return_1=0;
tl_yychar=tl_yylex(0);
return_1=1;
RValue=tl_level(0,1);
return RValue;
}
void  tl_parse(int $$Ext){
struct Node *tl_parse_n;
tl_parse_n=tl_formula(0);
if (tl_verbose){printf("formula: ");
put_uform(0);
printf("\n");
}
;
trans(0,tl_parse_n);
}
Node*  right_linked(int $$Ext,Node* n){
Node*  RValue=0;
int return_1;
struct Node *right_linked_2_3_tmp;
return_1=0;
if (!n){return_1=1;
RValue=n;
}
;
if (return_1==0){if ((n->ntyp==AND_1) || (n->ntyp==OR_1)){while((n->lft) && (n->lft->ntyp==n->ntyp)){right_linked_2_3_tmp=n->lft;
n->lft=right_linked_2_3_tmp->rgt;
right_linked_2_3_tmp->rgt=n;
n=right_linked_2_3_tmp;
}
;
}
;
n->lft=right_linked(0,n->lft);
n->rgt=right_linked(0,n->rgt);
return_1=1;
RValue=n;
}
;
return RValue;
}
Node*  canonical(int $$Ext,Node* n){
Node*  RValue=0;
int return_1;
struct Node *canonical_m;
return_1=0;
if (!n){return_1=1;
RValue=n;
}
;
if (return_1==0){canonical_m=in_cache(0,n);
if (canonical_m){return_1=1;
RValue=canonical_m;
}
;
if (return_1==0){n->rgt=canonical(0,n->rgt);
n->lft=canonical(0,n->lft);
return_1=1;
RValue=cached(0,n);
}
;
}
;
return RValue;
}
Node*  push_negation(int $$Ext,Node* n){
Node*  RValue=0;
int return_1;
struct Node *push_negation_m;
int switch_1;
int break_1$;
int nm_13$;
struct Node *push_negation_2_temp$_1;
struct Node *push_negation_2_temp$_2;
struct Node *push_negation_2_temp$_3;
struct Node *push_negation_2_temp$_4;
struct Node *push_negation_temp$_5;
return_1=0;
if (!(n->ntyp==NOT)){tl_explain(0,n->ntyp);
Fatal(0,": assertion failed\n",NULL);
}
;
break_1$=0;
switch_1=0;
nm_13$=n->lft->ntyp;
if ((nm_13$==TRUE) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
releasenode(0,0,n->lft);
n->lft=NULL;
n->ntyp=FALSE;
break_1$=1;
}
;
if ((nm_13$==FALSE) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
releasenode(0,0,n->lft);
n->lft=NULL;
n->ntyp=TRUE;
break_1$=1;
}
;
if ((nm_13$==NOT) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
push_negation_m=n->lft->lft;
releasenode(0,0,n->lft);
n->lft=NULL;
releasenode(0,0,n);
n=push_negation_m;
break_1$=1;
}
;
if ((nm_13$==V_OPER) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
n->ntyp=U_OPER;
push_negation_m=n->lft->rgt;
n->lft->rgt=NULL;
push_negation_2_temp$_1=tl_nn(0,NOT,push_negation_m,NULL);
n->rgt=push_negation(0,push_negation_2_temp$_1);
n->lft->ntyp=NOT;
push_negation_m=n->lft;
n->lft=push_negation(0,push_negation_m);
break_1$=1;
}
;
if ((nm_13$==U_OPER) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
n->ntyp=V_OPER;
push_negation_m=n->lft->rgt;
n->lft->rgt=NULL;
push_negation_2_temp$_2=tl_nn(0,NOT,push_negation_m,NULL);
n->rgt=push_negation(0,push_negation_2_temp$_2);
n->lft->ntyp=NOT;
push_negation_m=n->lft;
n->lft=push_negation(0,push_negation_m);
break_1$=1;
}
;
if ((nm_13$==AND_1) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
n->ntyp=OR_1;
push_negation_m=n->lft->rgt;
n->lft->rgt=NULL;
push_negation_2_temp$_3=tl_nn(0,NOT,push_negation_m,NULL);
n->rgt=push_negation(0,push_negation_2_temp$_3);
n->lft->ntyp=NOT;
push_negation_m=n->lft;
n->lft=push_negation(0,push_negation_m);
break_1$=1;
}
;
if ((nm_13$==OR_1) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
n->ntyp=AND_1;
push_negation_m=n->lft->rgt;
n->lft->rgt=NULL;
push_negation_2_temp$_4=tl_nn(0,NOT,push_negation_m,NULL);
n->rgt=push_negation(0,push_negation_2_temp$_4);
n->lft->ntyp=NOT;
push_negation_m=n->lft;
n->lft=push_negation(0,push_negation_m);
break_1$=1;
}
;
push_negation_temp$_5=right_linked(0,n);
return_1=1;
RValue=canonical(0,push_negation_temp$_5);
return RValue;
}
void  addcan(int $$Ext,int tok,Node* n){
int goto_1;
int return_1;
struct Node *addcan_m,*addcan_prev;
struct Node **addcan_ptr;
struct Node *addcan_N;
struct Symbol *addcan_s,*addcan_t;
int addcan_cmp;
goto_1=0;
return_1=0;
addcan_prev=NULL;
if (!n){return_1=1;
}
;
if (return_1==0){if (n->ntyp==tok){addcan(0,tok,n->rgt);
addcan(0,tok,n->lft);
return_1=1;
}
;
if (return_1==0){addcan_N=dupnode(0,n);
if (!can){can=addcan_N;
return_1=1;
}
;
if (return_1==0){addcan_s=DoDump(0,addcan_N);
if ((can->ntyp)!=(tok)){addcan_ptr=&can;
goto_1=1;
}
;
if (goto_1==0){addcan_prev=NULL;
addcan_m=can;
while(((return_1==0) && (addcan_m->ntyp==tok)) && (addcan_m->rgt)){addcan_t=DoDump(0,addcan_m->lft);
addcan_cmp=strcmp(addcan_s->name,addcan_t->name);
if (addcan_cmp==0){return_1=1;
}
;
if (return_1==0){if (addcan_cmp<0){if (!addcan_prev){can=tl_nn(0,tok,addcan_N,can);
return_1=1;
} else {addcan_ptr=&addcan_prev->rgt;
goto_1=1;
}
;
}
;
}
;
if (return_1==0){if (goto_1==0){struct Node *$$$addcan_prev$8;
$$$addcan_prev$8=addcan_prev;
$$$addcan_prev$8=addcan_m;
struct Node *$$$addcan_m$9;
$$$addcan_m$9=addcan_m;
$$$addcan_m$9=addcan_m->rgt;
addcan_prev=$$$addcan_prev$8;
addcan_m=$$$addcan_m$9;
}
;
}
;
}
;
if (return_1==0){if (goto_1==0){addcan_ptr=&addcan_prev->rgt;
}
;
}
;
}
;
}
;
}
;
}
;
if (return_1==0){addcan_t=DoDump(0,(*(addcan_ptr)));
addcan_cmp=strcmp(addcan_s->name,addcan_t->name);
if (addcan_cmp==0){return_1=1;
}
;
if (return_1==0){if (addcan_cmp<0){(*(addcan_ptr))=tl_nn(0,tok,addcan_N,(*(addcan_ptr)));
} else {(*(addcan_ptr))=tl_nn(0,tok,(*(addcan_ptr)),addcan_N);
}
;
}
;
}
;
}
void  marknode(int $$Ext,int tok,Node* m){
if ((m->ntyp)!=(tok)){releasenode(0,0,m->rgt);
m->rgt=NULL;
}
;
m->ntyp=-1;
}
Node*  Canonical(int $$Ext,Node* n){
Node*  RValue=0;
int continue_1;
int goto_1;
int return_1;
struct Node *Canonical_m,*Canonical_p,*Canonical_k1,*Canonical_k2,*Canonical_prev,*Canonical_dflt;
int Canonical_tok;
continue_1=0;
goto_1=0;
return_1=0;
Canonical_dflt=NULL;
if (!n){return_1=1;
RValue=n;
}
;
if (return_1==0){Canonical_tok=n->ntyp;
if (((Canonical_tok)!=(AND_1)) && ((Canonical_tok)!=(OR_1))){return_1=1;
RValue=n;
}
;
if (return_1==0){can=NULL;
addcan(0,Canonical_tok,n);
if (0){printf("\nA0: ");
}
;
if (0){dump(0,can);
}
;
if (0){printf("\nA1: ");
}
;
if (0){dump(0,n);
}
;
if (0){printf("\n");
}
;
releasenode(0,1,n);
if (Canonical_tok==AND_1){continue_1=0;
Canonical_m=can;
while(Canonical_m){continue_1=0;
Canonical_k1=((Canonical_m->ntyp==AND_1) ?Canonical_m->lft : Canonical_m );
if (Canonical_k1->ntyp==TRUE){marknode(0,AND_1,Canonical_m);
Canonical_dflt=tl_nn(0,TRUE,NULL,NULL);
continue_1=1;
Canonical_m=((Canonical_m->ntyp==AND_1) ?Canonical_m->rgt : NULL );
}
;
if (continue_1==0){if (Canonical_k1->ntyp==FALSE){releasenode(0,1,can);
can=tl_nn(0,FALSE,NULL,NULL);
goto_1=1;
}
;
if (goto_1==0){Canonical_m=((Canonical_m->ntyp==AND_1) ?Canonical_m->rgt : NULL );
}
;
}
;
}
;
continue_1=0;
if (goto_1==0){Canonical_m=can;
while(Canonical_m){continue_1=0;
Canonical_p=can;
while(Canonical_p){continue_1=0;
if (((Canonical_p==Canonical_m) || (Canonical_p->ntyp==-1)) || (Canonical_m->ntyp==-1)){continue_1=1;
Canonical_p=((Canonical_p->ntyp==AND_1) ?Canonical_p->rgt : NULL );
}
;
if (continue_1==0){Canonical_k1=((Canonical_m->ntyp==AND_1) ?Canonical_m->lft : Canonical_m );
Canonical_k2=((Canonical_p->ntyp==AND_1) ?Canonical_p->lft : Canonical_p );
if (isequal(1,Canonical_k1,Canonical_k2)){marknode(0,AND_1,Canonical_p);
continue_1=1;
Canonical_p=((Canonical_p->ntyp==AND_1) ?Canonical_p->rgt : NULL );
}
;
if (continue_1==0){if (anywhere(1,OR_1,Canonical_k1,Canonical_k2)){marknode(0,AND_1,Canonical_p);
continue_1=1;
Canonical_p=((Canonical_p->ntyp==AND_1) ?Canonical_p->rgt : NULL );
}
;
if (continue_1==0){if ((Canonical_k2->ntyp==U_OPER) && (anywhere(1,AND_1,Canonical_k2->rgt,can))){marknode(0,AND_1,Canonical_p);
continue_1=1;
Canonical_p=((Canonical_p->ntyp==AND_1) ?Canonical_p->rgt : NULL );
}
;
if (continue_1==0){Canonical_p=((Canonical_p->ntyp==AND_1) ?Canonical_p->rgt : NULL );
}
;
}
;
}
;
}
;
}
;
continue_1=0;
Canonical_m=((Canonical_m->ntyp==AND_1) ?Canonical_m->rgt : NULL );
}
;
}
;
}
;
if (goto_1==0){if (Canonical_tok==OR_1){continue_1=0;
Canonical_m=can;
while(Canonical_m){continue_1=0;
Canonical_k1=((Canonical_m->ntyp==OR_1) ?Canonical_m->lft : Canonical_m );
if (Canonical_k1->ntyp==FALSE){marknode(0,OR_1,Canonical_m);
Canonical_dflt=tl_nn(0,FALSE,NULL,NULL);
continue_1=1;
Canonical_m=((Canonical_m->ntyp==OR_1) ?Canonical_m->rgt : NULL );
}
;
if (continue_1==0){if (Canonical_k1->ntyp==TRUE){releasenode(0,1,can);
can=tl_nn(0,TRUE,NULL,NULL);
goto_1=1;
}
;
if (goto_1==0){Canonical_m=((Canonical_m->ntyp==OR_1) ?Canonical_m->rgt : NULL );
}
;
}
;
}
;
continue_1=0;
if (goto_1==0){Canonical_m=can;
while(Canonical_m){continue_1=0;
Canonical_p=can;
while(Canonical_p){continue_1=0;
if (((Canonical_p==Canonical_m) || (Canonical_p->ntyp==-1)) || (Canonical_m->ntyp==-1)){continue_1=1;
Canonical_p=((Canonical_p->ntyp==OR_1) ?Canonical_p->rgt : NULL );
}
;
if (continue_1==0){Canonical_k1=((Canonical_m->ntyp==OR_1) ?Canonical_m->lft : Canonical_m );
Canonical_k2=((Canonical_p->ntyp==OR_1) ?Canonical_p->lft : Canonical_p );
if (isequal(1,Canonical_k1,Canonical_k2)){marknode(0,OR_1,Canonical_p);
continue_1=1;
Canonical_p=((Canonical_p->ntyp==OR_1) ?Canonical_p->rgt : NULL );
}
;
if (continue_1==0){if (anywhere(1,AND_1,Canonical_k1,Canonical_k2)){marknode(0,OR_1,Canonical_p);
continue_1=1;
Canonical_p=((Canonical_p->ntyp==OR_1) ?Canonical_p->rgt : NULL );
}
;
if (continue_1==0){if (((Canonical_k2->ntyp==V_OPER) && (Canonical_k2->lft->ntyp==FALSE)) && (anywhere(1,AND_1,Canonical_k2->rgt,can))){marknode(0,OR_1,Canonical_p);
continue_1=1;
Canonical_p=((Canonical_p->ntyp==OR_1) ?Canonical_p->rgt : NULL );
}
;
if (continue_1==0){Canonical_p=((Canonical_p->ntyp==OR_1) ?Canonical_p->rgt : NULL );
}
;
}
;
}
;
}
;
}
;
continue_1=0;
Canonical_m=((Canonical_m->ntyp==OR_1) ?Canonical_m->rgt : NULL );
}
;
}
;
}
;
if (goto_1==0){continue_1=0;
struct Node *$$$Canonical_m$10;
$$$Canonical_m$10=Canonical_m;
$$$Canonical_m$10=can;
struct Node *$$$Canonical_prev$11;
$$$Canonical_prev$11=Canonical_prev;
$$$Canonical_prev$11=NULL;
Canonical_m=$$$Canonical_m$10;
Canonical_prev=$$$Canonical_prev$11;
while(Canonical_m){continue_1=0;
if (Canonical_m->ntyp==-1){Canonical_k2=Canonical_m->rgt;
releasenode(0,0,Canonical_m);
if (!Canonical_prev){can=can->rgt;
Canonical_m=can;
} else {Canonical_prev->rgt=Canonical_k2;
Canonical_m=Canonical_prev->rgt;
if (((!(Canonical_prev->rgt)) && (Canonical_prev->lft)) && ((Canonical_prev->ntyp==AND_1) || (Canonical_prev->ntyp==OR_1))){Canonical_k1=Canonical_prev->lft;
Canonical_prev->ntyp=Canonical_prev->lft->ntyp;
Canonical_prev->sym=Canonical_prev->lft->sym;
Canonical_prev->rgt=Canonical_prev->lft->rgt;
Canonical_prev->lft=Canonical_prev->lft->lft;
releasenode(0,0,Canonical_k1);
}
;
}
;
continue_1=1;
}
;
if (continue_1==0){Canonical_prev=Canonical_m;
Canonical_m=Canonical_m->rgt;
}
;
}
;
continue_1=0;
}
;
}
;
}
;
}
;
if (return_1==0){if (0){printf("A2: ");
}
;
if (0){dump(0,can);
}
;
if (0){printf("\n");
}
;
if (!can){if (!Canonical_dflt){fatal(0,"cannot happen, Canonical",NULL);
}
;
return_1=1;
RValue=Canonical_dflt;
}
;
if (return_1==0){return_1=1;
RValue=can;
}
;
}
;
return RValue;
}
int * new_set(int $$Ext,int type){
int * RValue=0;
int return_1;
return_1=0;
return_1=1;
RValue=(int *)(tl_emalloc(1,(((type==1) ?sym_size : ((type==2) ?scc_size : node_size ) )*4)));
return RValue;
}
int * clear_set(int $$Ext,int *l,int type){
int * RValue=0;
int return_1;
int clear_set_i;
return_1=0;
clear_set_i=0;
while(clear_set_i<((type==1) ?sym_size : ((type==2) ?scc_size : node_size ) )){l[clear_set_i]=0;
clear_set_i=(clear_set_i)+(1);
}
;
return_1=1;
RValue=l;
return RValue;
}
int * make_set(int $$Ext,int n,int type){
int * RValue=0;
int return_1;
int *make_set_temp$_1;
int *make_set_l;
return_1=0;
make_set_temp$_1=new_set(0,type);
make_set_l=clear_set(0,make_set_temp$_1,type);
if (n==-1){return_1=1;
RValue=make_set_l;
}
;
if (return_1==0){make_set_l[(n/ mod)]=(1)<<((n%mod));
return_1=1;
RValue=make_set_l;
}
;
return RValue;
}
void  copy_set(int $$Ext,int *from,int *to,int type){
int copy_set_i;
copy_set_i=0;
while(copy_set_i<((type==1) ?sym_size : ((type==2) ?scc_size : node_size ) )){to[copy_set_i]=from[copy_set_i];
copy_set_i=(copy_set_i)+(1);
}
;
}
int * dup_set(int $$Ext,int *l,int type){
int * RValue=0;
int return_1;
int dup_set_i,*dup_set_m;
return_1=0;
dup_set_m=new_set(0,type);
dup_set_i=0;
while(dup_set_i<((type==1) ?sym_size : ((type==2) ?scc_size : node_size ) )){dup_set_m[dup_set_i]=l[dup_set_i];
dup_set_i=(dup_set_i)+(1);
}
;
return_1=1;
RValue=dup_set_m;
return RValue;
}
void  merge_sets(int $$Ext,int *l1,int *l2,int type){
int merge_sets_i;
merge_sets_i=0;
while(merge_sets_i<((type==1) ?sym_size : ((type==2) ?scc_size : node_size ) )){l1[merge_sets_i]=(l1[merge_sets_i])|(l2[merge_sets_i]);
merge_sets_i=(merge_sets_i)+(1);
}
;
}
void  do_merge_sets(int $$Ext,int *l,int *l1,int *l2,int type){
int do_merge_sets_i;
do_merge_sets_i=0;
while(do_merge_sets_i<((type==1) ?sym_size : ((type==2) ?scc_size : node_size ) )){l[do_merge_sets_i]=(l1[do_merge_sets_i])|(l2[do_merge_sets_i]);
do_merge_sets_i=(do_merge_sets_i)+(1);
}
;
}
int * intersect_sets(int $$Ext,int *l1,int *l2,int type){
int * RValue=0;
int return_1;
int intersect_sets_i,*intersect_sets_l;
return_1=0;
intersect_sets_l=new_set(0,type);
intersect_sets_i=0;
while(intersect_sets_i<((type==1) ?sym_size : ((type==2) ?scc_size : node_size ) )){intersect_sets_l[intersect_sets_i]=(l1[intersect_sets_i])&(l2[intersect_sets_i]);
intersect_sets_i=(intersect_sets_i)+(1);
}
;
return_1=1;
RValue=intersect_sets_l;
return RValue;
}
int  empty_intersect_sets(int $$Ext,int *l1,int *l2,int type){
int  RValue=0;
int return_1;
int empty_intersect_sets_i,empty_intersect_sets_test;
return_1=0;
empty_intersect_sets_test=0;
empty_intersect_sets_i=0;
while(empty_intersect_sets_i<((type==1) ?sym_size : ((type==2) ?scc_size : node_size ) )){empty_intersect_sets_test=(empty_intersect_sets_test)|((l1[empty_intersect_sets_i])&(l2[empty_intersect_sets_i]));
empty_intersect_sets_i=(empty_intersect_sets_i)+(1);
}
;
return_1=1;
RValue=!empty_intersect_sets_test;
return RValue;
}
void  add_set(int $$Ext,int *l,int n){
l[(n/ mod)]=(l[(n/ mod)])|((1)<<((n%mod)));
}
void  rem_set(int $$Ext,int *l,int n){
l[(n/ mod)]=(l[(n/ mod)])&((-1)-((1)<<((n%mod))));
}
void  spin_print_set(int $$Ext,int *pos,int *neg){
int spin_print_set_i,spin_print_set_j,spin_print_set_start;
spin_print_set_start=1;
spin_print_set_i=0;
while(spin_print_set_i<sym_size){spin_print_set_j=0;
while(spin_print_set_j<mod){if ((pos[spin_print_set_i])&((1)<<(spin_print_set_j))){if (!spin_print_set_start){printf(" && ");
}
;
printf("%p",sym_table[((mod*spin_print_set_i))+(spin_print_set_j)]);
spin_print_set_start=0;
}
;
if ((neg[spin_print_set_i])&((1)<<(spin_print_set_j))){if (!spin_print_set_start){printf(" && ");
}
;
printf("!");
printf("%p",sym_table[((mod*spin_print_set_i))+(spin_print_set_j)]);
spin_print_set_start=0;
}
;
spin_print_set_j=(spin_print_set_j)+(1);
}
;
spin_print_set_i=(spin_print_set_i)+(1);
}
;
if (spin_print_set_start){printf("1");
}
;
}
void  print_set(int $$Ext,int *l,int type){
int return_1;
int print_set_i,print_set_j,print_set_start;
int switch_1;
int break_1$;
int nm_14$;
return_1=0;
print_set_start=1;
if ((type)!=(1)){printf("{");
}
;
print_set_i=0;
while(print_set_i<((type==1) ?sym_size : ((type==2) ?scc_size : node_size ) )){print_set_j=0;
while(print_set_j<mod){if ((l[print_set_i])&((1)<<(print_set_j))){break_1$=0;
switch_1=0;
nm_14$=type;
if ((nm_14$==0) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
}
;
if ((nm_14$==2) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
if (!print_set_start){printf(",");
}
;
;
printf("i");
break_1$=1;
}
;
if ((nm_14$==1) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
if (!print_set_start){printf(" & ");
}
;
printf("%p",sym_table[((mod*print_set_i))+(print_set_j)]);
break_1$=1;
}
;
print_set_start=0;
}
;
print_set_j=(print_set_j)+(1);
}
;
print_set_i=(print_set_i)+(1);
}
;
if ((type)!=(1)){printf("}");
}
;
}
int  empty_set(int $$Ext,int *l,int type){
int  RValue=0;
int return_1;
int empty_set_i,empty_set_test;
return_1=0;
empty_set_test=0;
empty_set_i=0;
while(empty_set_i<((type==1) ?sym_size : ((type==2) ?scc_size : node_size ) )){empty_set_test=(empty_set_test)|(l[empty_set_i]);
empty_set_i=(empty_set_i)+(1);
}
;
return_1=1;
RValue=!empty_set_test;
return RValue;
}
int  same_sets(int $$Ext,int *l1,int *l2,int type){
int  RValue=0;
int return_1;
int same_sets_i,same_sets_test;
return_1=0;
same_sets_test=1;
same_sets_i=0;
while(same_sets_i<((type==1) ?sym_size : ((type==2) ?scc_size : node_size ) )){same_sets_test=(same_sets_test)&(l1[same_sets_i]==l2[same_sets_i]);
same_sets_i=(same_sets_i)+(1);
}
;
return_1=1;
RValue=same_sets_test;
return RValue;
}
int  included_set(int $$Ext,int *l1,int *l2,int type){
int  RValue=0;
int return_1;
int included_set_i,included_set_test;
return_1=0;
included_set_test=0;
included_set_i=0;
while(included_set_i<((type==1) ?sym_size : ((type==2) ?scc_size : node_size ) )){included_set_test=(included_set_test)|((l1[included_set_i])&(~(l2[included_set_i])));
included_set_i=(included_set_i)+(1);
}
;
return_1=1;
RValue=!included_set_test;
return RValue;
}
int  in_set(int $$Ext,int *l,int n){
int  RValue=0;
int return_1;
return_1=0;
return_1=1;
RValue=(l[(n/ mod)])&((1)<<((n%mod)));
return RValue;
}
int * list_set(int $$Ext,int *l,int type){
int * RValue=0;
int return_1;
int list_set_i,list_set_j,list_set_size,*list_set_list$;
return_1=0;
list_set_size=1;
list_set_i=0;
while(list_set_i<((type==1) ?sym_size : ((type==2) ?scc_size : node_size ) )){list_set_j=0;
while(list_set_j<mod){if ((l[list_set_i])&((1)<<(list_set_j))){list_set_size=(list_set_size)+(1);
}
;
list_set_j=(list_set_j)+(1);
}
;
list_set_i=(list_set_i)+(1);
}
;
list_set_list$=(int *)(tl_emalloc(1,(list_set_size*4)));
list_set_list$[0]=list_set_size;
list_set_size=1;
list_set_i=0;
while(list_set_i<((type==1) ?sym_size : ((type==2) ?scc_size : node_size ) )){list_set_j=0;
while(list_set_j<mod){if ((l[list_set_i])&((1)<<(list_set_j))){list_set_list$[list_set_size]=((mod*list_set_i))+(list_set_j);
list_set_size=(list_set_size)+(1);
}
;
list_set_j=(list_set_j)+(1);
}
;
list_set_i=(list_set_i)+(1);
}
;
return_1=1;
RValue=list_set_list$;
return RValue;
}
int  dump_cond(int $$Ext,Node* pp,Node* r,int first){
int  RValue=0;
int return_1;
struct Node *dump_cond_q;
int dump_cond_frst;
struct Node *dump_cond_temp$_1;
return_1=0;
dump_cond_frst=first;
if (!pp){return_1=1;
RValue=dump_cond_frst;
}
;
if (return_1==0){dump_cond_q=dupnode(0,pp);
dump_cond_temp$_1=right_linked(0,dump_cond_q);
dump_cond_q=canonical(0,dump_cond_temp$_1);
if ((((dump_cond_q->ntyp==PREDICATE) || (dump_cond_q->ntyp==NOT)) || (dump_cond_q->ntyp==OR_1)) || (dump_cond_q->ntyp==FALSE)){if (!dump_cond_frst){printf(" && ");
}
;
dump(0,dump_cond_q);
dump_cond_frst=0;
} else {if ((dump_cond_q->ntyp==V_OPER) && (!(anywhere(1,AND_1,dump_cond_q->rgt,r)))){dump_cond_frst=dump_cond(0,dump_cond_q->rgt,r,dump_cond_frst);
} else {if (dump_cond_q->ntyp==AND_1){dump_cond_frst=dump_cond(0,dump_cond_q->lft,r,dump_cond_frst);
dump_cond_frst=dump_cond(0,dump_cond_q->rgt,r,dump_cond_frst);
}
;
}
;
}
;
return_1=1;
RValue=dump_cond_frst;
}
;
return RValue;
}
void  sdump(int $$Ext,Node* n){
int return_1;
int switch_1;
int break_1$;
int nm_15$;
return_1=0;
break_1$=0;
switch_1=0;
nm_15$=n->ntyp;
if ((nm_15$==PREDICATE) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
strcat(dumpbuf,n->sym->name);
break_1$=1;
}
;
if ((nm_15$==U_OPER) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
strcat(dumpbuf,"U");
sdump(0,n->rgt);
sdump(0,n->lft);
break_1$=1;
}
;
if ((nm_15$==V_OPER) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
strcat(dumpbuf,"V");
sdump(0,n->rgt);
sdump(0,n->lft);
break_1$=1;
}
;
if ((nm_15$==OR_1) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
strcat(dumpbuf,"|");
sdump(0,n->rgt);
sdump(0,n->lft);
break_1$=1;
}
;
if ((nm_15$==AND_1) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
strcat(dumpbuf,"&");
sdump(0,n->rgt);
sdump(0,n->lft);
break_1$=1;
}
;
if ((nm_15$==NOT) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
strcat(dumpbuf,"!");
sdump(0,n->lft);
break_1$=1;
}
;
if ((nm_15$==TRUE) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
strcat(dumpbuf,"T");
break_1$=1;
}
;
if ((nm_15$==FALSE) || (((switch_1==1) && (break_1$==0)) && (return_1==0))){switch_1=1;
strcat(dumpbuf,"F");
break_1$=1;
}
;
if ((break_1$==0) && (return_1==0)){strcat(dumpbuf,"?");
break_1$=1;
}
;
}
Symbol*  DoDump(int $$Ext,Node* n){
Symbol*  RValue=0;
int return_1;
return_1=0;
if (!n){return_1=1;
RValue=NULL;
}
;
if (return_1==0){if (n->ntyp==PREDICATE){return_1=1;
RValue=n->sym;
}
;
if (return_1==0){dumpbuf[0]='\0';
sdump(0,n);
return_1=1;
RValue=tl_lookup(0,dumpbuf);
}
;
}
;
return RValue;
}
void  trans(int $$Ext,Node* p){
int return_1;
return_1=0;
if ((!p) || (tl_errs)){return_1=1;
}
;
if (return_1==0){if ((tl_verbose) || (tl_terse)){printf("\t\n             \n");
}
;
if (tl_terse){return_1=1;
}
;
if (return_1==0){mk_alternating(0,p);
mk_generalized(0);
mk_buchi(0);
}
;
}
;
}

int main() {
while (true){
while ($$length > 0){
if ($$flag[$$length - 1] == 1){
$$length--;}
else {
$$flag[$$length - 1] = 1; break;}}
if ( ($$length == 0 && $$flag[0] == 1) || ($$current == 0 && $$firstTime==1)){break;}
$$current = 0;
printf("Path Number: %d",$$pathNum);
printf("\n");
ALWAYS=257;
AND_1=258;
EQUIV=259;
EVENTUALLY=260;
FALSE=261;
IMPLIES=262;
NOT=263;
OR_1=264;
PREDICATE=265;
TRUE=266;
U_OPER=267;
V_OPER=268;
tl_stats=0;
tl_simp_log=1;
tl_simp_diff=1;
tl_simp_fly=1;
tl_simp_scc=1;
tl_fjtofj=1;
tl_errs=0;
tl_verbose=0;
tl_terse=0;
All_Mem=0;
hasuform=0;
cnt=0;
ltl_file=NULL;
add_ltl=NULL;
node_id=1;
sym_id=0;
astate_count=0;
atrans_count=0;
bstate_count=0;
btrans_count=0;
stored=NULL;
Caches=0;
CacheHits=0;
init_size=0;
gstate_id=1;
gstate_count=0;
gtrans_count=0;
atrans_list=NULL;
gtrans_list=NULL;
btrans_list=NULL;
aallocs=0;
afrees=0;
apool=0;
gallocs=0;
gfrees=0;
gpool=0;
ballocs=0;
bfrees=0;
bpool=0;
tl_yychar=0;
can=NULL;
mod=(8*4);
Stack_mx=0;
Max_Red=0;
Total=0;
main_1(0);
$$firstTime=1;
$$state_num=0;
printf("\n");
$$pathNum=$$pathNum+1;
}
return 0;
}
