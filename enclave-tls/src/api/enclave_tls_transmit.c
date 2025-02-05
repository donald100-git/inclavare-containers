/* Copyright (c) 2020-2021 Alibaba Cloud and Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <enclave-tls/api.h>
#include <enclave-tls/log.h>

#include "internal/core.h"

enclave_tls_err_t enclave_tls_transmit(enclave_tls_handle handle, void *buf,
				       size_t *buf_size)
{
	etls_core_context_t *ctx = (etls_core_context_t *)handle;

	ETLS_DEBUG("handle %p, buf %p, buf_size %Zd\n", ctx, buf, buf_size);

	if (!handle || !handle->tls_wrapper || !handle->tls_wrapper->opts ||
	    !handle->tls_wrapper->opts->transmit || !buf || !buf_size)
		return -ENCLAVE_TLS_ERR_INVALID;

	enclave_tls_err_t err;
	err = handle->tls_wrapper->opts->transmit(handle->tls_wrapper, buf,
						  buf_size);
	if (err != TLS_WRAPPER_ERR_NONE)
		return err;

	return ENCLAVE_TLS_ERR_NONE;
}
