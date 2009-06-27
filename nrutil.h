//extern long double *vector(int nl,int nh);
extern long double **matrix(int nrl, int nrh, int ncl, int nch);
extern long double **convert_matrix(long double *a, int nrl, int nrh, int ncl, int nch);
extern long double *dvector(int nl, int nh);
extern long double **dmatrix(int nrl, int nrh, int ncl, int nch);
extern int *ivector(int nl, int nh);
extern int **imatrix(int nrl, int nrh, int ncl, int nch);
extern long double **submatrix(long double **a, int oldrl, int oldrh, int oldcl,int oldch,int newrl, int newcl);
extern void free_vector(long double *v, int nl, int nh);
extern void free_dvector(long double *v, int nl, int nh);
extern void free_ivector(int *v, int nl, int nh);
extern void free_matrix(long double **m, int nrl, int nrh, int ncl, int nch);
extern void free_dmatrix(long double **m, int nr1, int nrh, int nc1, int nch);
extern void free_imatrix(int **m, int nr1, int nrh, int nc1, int nch);
extern void free_submatrix(long double **b, int nrl,int nrh, int ncl,int nch);
extern void free_convert_matrix(long double **b,int nrl, int nrh,int ncl,int nch);
extern void nrerror(char *error_text);
extern long double ****viertensor(int n1,int nh1,int n2,int nh2,int n3,int nh3,int n4,int nh4);
extern void free_viertensor(long double ****tensor,int n1,int nh1,int n2,int nh2,int n3,int nh3,int n4,int nh4);
extern long double **save_matrix(int nrl, int nrh, int ncl, int nch);
