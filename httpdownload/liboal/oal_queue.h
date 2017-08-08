#ifndef _OAL_QUEUE_H_
#define _OAL_QUEUE_H_

#include "oal_type.h"



/** Structure used for queue definition */
typedef struct  {
	/** Size of the queue */
	int size;
} OAL_QUEUE_POOL;

/** Define OS Queue pool
*
* This macro helps define the name and size of the queue to be created
* using the function os_queue_create().
*/
#define OAL_QUEUE_POOL_DEFINE(poolname, poolsize)	OAL_QUEUE_POOL poolname = { poolsize };

typedef void* OAL_QUEUE;

/** Create an OS queue
*
* This function creates a new queue instance. This allocates the storage
* required by the new queue and returns a handle for the queue.
*
* @param[out] qhandle Pointer to the handle of the newly created queue
* @param[in] name String specifying the name of the queue
* @param[in] msgsize The number of bytes each item in the queue will
* require. Items are queued by copy, not by reference, so this is the
* number of bytes that will be copied for each posted item. Each item on
* the queue must be the same size.
* @param[in] poolname The object of the type \ref OAL_QUEUE_POOL. The
* helper macro os_queue_pool_define() helps to define this object.
*
* @return OAL_SUCCESS if queue creation was successful
* @return OAL_FAILED if queue creation failed
*/
int OAL_QueueCreate(OAL_QUEUE *qhandle, const char *name, int msgsize, OAL_QUEUE_POOL *poolname);

/** Post an item to the back of the queue.
*
* This function posts an item to the back of a queue. The item is queued by
* copy, not by reference. This function can also be called from an interrupt
* service routine.
*
* @param[in] qhandle Pointer to the handle of the queue
* @param[in] msg A pointer to the item that is to be placed on the
* queue. The size of the items the queue will hold was defined when the
* queue was created, so this many bytes will be copied from msg
* into the queue storage area.
* @param[in] wait The maximum amount of time, in OS ticks, the task should
* block waiting for space to become available on the queue, should it already
* be full. The function os_msec_to_ticks() can be used to convert from
* real-time to OS ticks. The special values \ref OS_WAIT_FOREVER and \ref
* OS_NO_WAIT are provided to respectively wait infinitely or return
* immediately.
*
* @return OAL_SUCCESS if send operation was successful
* @return OAL_ENOTSUPPORT if invalid parameters are passed
* @return OAL_FAILED if send operation failed
*/
int OAL_QueueSend(OAL_QUEUE *qhandle, const void *msg, unsigned long wait);

/** Receive an item from queue
*
* This function receives an item from a queue. The item is received by copy so
* a buffer of adequate size must be provided. The number of bytes copied into
* the buffer was defined when the queue was created.
*
* \note This function must not be used in an interrupt service routine.
*
* @param[in] qhandle Pointer to handle of the queue
* @param[out] msg Pointer to the buffer into which the received item will
* be copied. The size of the items in the queue was defined when the queue was
* created. This pointer should point to a buffer as many bytes in size.
* @param[in] wait The maximum amount of time, in OS ticks, the task should
* block waiting for messages to arrive on the queue, should it already
* be empty. The function os_msec_to_ticks() can be used to convert from
* real-time to OS ticks. The special values \ref OS_WAIT_FOREVER and \ref
* OS_NO_WAIT are provided to respectively wait infinitely or return
* immediately.
*
* @return OAL_SUCCESS if receive operation was successful
* @return OAL_ENOTSUPPORT if invalid parameters are passed
* @return OAL_FAILED if receive operation failed
*/
int OAL_QueueRecv(OAL_QUEUE *qhandle, void *msg, unsigned long wait);

/** Delete queue
*
* This function deletes a queue. It frees all the memory allocated for storing
* of items placed on the queue.
*
* @param[in] qhandle Pointer to handle of the queue to be deleted.
*
* @return Currently always returns OAL_SUCCESS
*/
int OAL_QueueDelete(OAL_QUEUE *qhandle);

/** Return the number of messages stored in queue.
*
* @param[in] qhandle Pointer to handle of the queue to be queried.
*
* @returns Number of items in the queue
* @return OAL_ENOTSUPPORT if invalid parameters are passed
*/
int OAL_QueueGetMsgsWaiting(OAL_QUEUE *qhandle);


#endif


