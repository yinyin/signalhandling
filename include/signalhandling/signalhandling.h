#ifndef _SIGNALHANDLING_SIGNALHANDLING_H_
#define _SIGNALHANDLING_SIGNALHANDLING_H_ 1

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*signalhandler_callable)(int);

int ignore_signal(int sig);

int setup_stop_signal_handler(signalhandler_callable handler_func);

int setup_signal_handler(int sig, signalhandler_callable handler_func);
int setup_signal_handler_with_flags(int sig,
                                    signalhandler_callable handler_func,
                                    int sa_flags);

#ifdef __cplusplus
}
#endif

#endif /* _SIGNALHANDLING_SIGNALHANDLING_H_ */
