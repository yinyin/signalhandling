#ifndef _SIGNALHANDLING_SIGNALHANDLING_H_
#define _SIGNALHANDLING_SIGNALHANDLING_H_ 1

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*signalhandling_handler_callable)(int);

int signalhandling_ignore_signal(int sig);

int signalhandling_setup_stop_signal_handler(
        signalhandling_handler_callable handler_func);
int signalhandling_setup_stop_signal_handler_with_flags(
        signalhandling_handler_callable handler_func,
        int sa_flags);

int signalhandling_setup_handler(int sig,
                                 signalhandling_handler_callable handler_func);
int signalhandling_setup_handler_with_flags(
        int sig,
        signalhandling_handler_callable handler_func,
        int sa_flags);

#ifdef __cplusplus
}
#endif

#endif /* _SIGNALHANDLING_SIGNALHANDLING_H_ */
