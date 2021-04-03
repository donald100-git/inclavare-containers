#include <enclave-tls/err.h>
#include <enclave-tls/tls_wrapper.h>
#include <enclave-tls/log.h>
#include "wolfssl_sgx.h"

tls_wrapper_err_t wolfssl_sgx_negotiate(tls_wrapper_ctx_t *ctx, int fd)
{
	ETLS_DEBUG("ctx %p, fd %d\n", ctx, fd);

	tls_wrapper_err_t err;
	ecall_negotiate((sgx_enclave_id_t)ctx->enclave_id, &err, ctx, fd);

	return err;
}
