// 底层网络库需要的fd、事件等数据共享结构体
typedef struct aeApiState {
    // ...
} aeApiState;

// 创建aeApiState, 本质上是创建底层网络库对象的句柄，在此基础上才能进行网络事件的监听处理
static int aeApiCreate(aeEventLoop *eventLoop) {
// 释放aeApiState这个共享结构体及其相关的资源
static void aeApiFree(aeEventLoop *eventLoop) {
// 修改底层网络库存放事件的容器大小(only epoll && kqueue)
static int aeApiResize(aeEventLoop *eventLoop, int setsize) {
// 将网络fd的读写操作交给网络库进行处理
static int aeApiAddEvent(aeEventLoop *eventLoop, int fd, int mask) {
// 从底层网络库中删除对某个fd的监听(一般服务器往客户端写完数据后，主动断开客户端连接时会使用)
static void aeApiDelEvent(aeEventLoop *eventLoop, int fd, int mask) {
// 轮询获取网络正在发生io读写事件的事件
static int aeApiPoll(aeEventLoop *eventLoop, struct timeval *tvp) {
// 获取底层网络库的名字，比如epool,kqueue等
static char *aeApiName(void) {
