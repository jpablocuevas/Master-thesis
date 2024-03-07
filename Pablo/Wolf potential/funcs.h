// ---------------- Defining some usefull types ------------------
typedef long double ld;

typedef  ld (*fp) (ld);

static ld pi = 3.1415926535;

// ------------------ Numerical integration functions -------------------
ld integral ( ld (*f)(ld), ld, ld, int);

ld gauss_exp (ld);

ld my_erfc (ld);

ld x_c (ld);

ld Wolf (ld, ld);

ld my_abs (ld);

// ------------------ File name functions -------------------

int count_digits (int);

char int_to_char (int n);

char *int_to_str (int);

char *file_name (int);
