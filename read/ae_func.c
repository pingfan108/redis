/* A simple event-driven programming library. Originally I wrote this code
 * for the Jim's event-loop (Jim is a Tcl interpreter) but later translated
 * it in form of a library for easy reuse.
 */

#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <poll.h>
#include <string.h>
#include <time.h>
#include <errno.h>

#include "ae.h"
#include "zmalloc.h"
#include "config.h"

aeEventLoop *aeCreateEventLoop(int setsize) {
}

/* Return the current set size. */
int aeGetSetSize(aeEventLoop *eventLoop) {
}

/* Resize the maximum set size of the event loop.
 * If the requested set size is smaller than the current set size, but
 * there is already a file descriptor in use that is >= the requested
 * set size minus one, AE_ERR is returned and the operation is not
 * performed at all.
 *
 * Otherwise AE_OK is returned and the operation is successful. */
int aeResizeSetSize(aeEventLoop *eventLoop, int setsize) {
}

void aeDeleteEventLoop(aeEventLoop *eventLoop) {
}

void aeStop(aeEventLoop *eventLoop) {
}

int aeCreateFileEvent(aeEventLoop *eventLoop, int fd, int mask,
{
}

void aeDeleteFileEvent(aeEventLoop *eventLoop, int fd, int mask)
{
}

int aeGetFileEvents(aeEventLoop *eventLoop, int fd) {
}

static void aeGetTime(long *seconds, long *milliseconds)
{
}

static void aeAddMillisecondsToNow(long long milliseconds, long *sec, long *ms) {
}

long long aeCreateTimeEvent(aeEventLoop *eventLoop, long long milliseconds,
{
}

int aeDeleteTimeEvent(aeEventLoop *eventLoop, long long id)
{
}

/* Search the first timer to fire.
 * This operation is useful to know how many time the select can be
 * put in sleep without to delay any event.
 * If there are no timers NULL is returned.
 *
 * Note that's O(N) since time events are unsorted.
 * Possible optimizations (not needed by Redis so far, but...):
 * 1) Insert the event in order, so that the nearest is just the head.
 * 2) Use a skiplist to have this operation as O(1) and insertion as O(log(N)).
 */
static aeTimeEvent *aeSearchNearestTimer(aeEventLoop *eventLoop)
{
}

/* Process time events */
static int processTimeEvents(aeEventLoop *eventLoop) {
}

/* Process every pending time event, then every pending file event
 * (that may be registered by time event callbacks just processed).
 * Without special flags the function sleeps until some file event
 * fires, or when the next time event occurs (if any).
 *
 * If flags is 0, the function does nothing and returns.
 * if flags has AE_ALL_EVENTS set, all the kind of events are processed.
 * if flags has AE_FILE_EVENTS set, file events are processed.
 * if flags has AE_TIME_EVENTS set, time events are processed.
 * if flags has AE_DONT_WAIT set the function returns ASAP until all
 * if flags has AE_CALL_AFTER_SLEEP set, the aftersleep callback is called.
 * the events that's possible to process without to wait are processed.
 *
 * The function returns the number of events processed. */
int aeProcessEvents(aeEventLoop *eventLoop, int flags)
{
}

/* Wait for milliseconds until the given file descriptor becomes
 * writable/readable/exception */
int aeWait(int fd, int mask, long long milliseconds) {
}

void aeMain(aeEventLoop *eventLoop) {
}

char *aeGetApiName(void) {
}

void aeSetBeforeSleepProc(aeEventLoop *eventLoop, aeBeforeSleepProc *beforesleep) {
}

void aeSetAfterSleepProc(aeEventLoop *eventLoop, aeBeforeSleepProc *aftersleep) {
}
