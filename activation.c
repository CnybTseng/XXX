#include <math.h>
#include "activation.h"

static void linear_activate(float *X, int n);
static void logistic_active(float *X, int n);
static void relu_activate(float *X, int n);

/** @brief 神经元激活函数.目前仅支持线性激活和线性整流激活.
 ** @param X 神经元原始输出或激活输出.
 ** @param n 神经元个数.
 ** @param activation 激活方法.
 **        activation=RELU,线性整流激活.
 **        activation=LINEAR,线性激活.
 **/
void activate(float *X, int n, ACTIVATION activation)
{
	if (activation == RELU) {
		relu_activate(X, n);
	} else if (activation == LINEAR){
		linear_activate(X, n);
	} else if (activation == LOGISTIC) {
		logistic_active(X, n);
	} else {
		fprintf(stderr, "Not implemented[%s:%d].\n", __FILE__, __LINE__);
	}
}

void linear_activate(float *X, int n)
{
	return;
}

void logistic_active(float *X, int n)
{
	for (int i = 0; i < n; ++i) {
		X[i] = 1 / (1 + exp(-X[i]));
	}
}

void relu_activate(float *X, int n)
{
	for (int i = 0; i < n; ++i) {
		X[i] = (X[i] > 0) * X[i];
	}
}