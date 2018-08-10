#include <signal.h>
#include <string.h>
#include <syslog.h>

#include "recordlogs/recordlogs.h"

#include "signalhandling/signalhandling.h"

int signalhandling_ignore_signal(int sig) {
    struct sigaction sigact;
    memset(&sigact, 0, sizeof(sigact));
    sigact.sa_handler = SIG_IGN;
    sigact.sa_flags = SA_RESTART;
    if (0 != sigaction(sig, &sigact, NULL)) {
        RECORD_ERROR(
                LOG_ERR, "failed on ignoring SIG%s signal", strsignal(sig));
        return -1;
    }
    return 0;
}

int signalhandling_setup_stop_signal_handler(
        signalhandling_handler_callable handler_func) {
    struct sigaction sigact;
    memset(&sigact, 0, sizeof(sigact));
    sigact.sa_handler = handler_func;
    sigact.sa_flags = SA_RESTART;
    if (0 != sigaction(SIGTERM, &sigact, NULL)) {
        RECORD_ERROR(LOG_ERR, "failed on setting up SIGTERM signal handler");
        return -1;
    }
    if (0 != sigaction(SIGINT, &sigact, NULL)) {
        RECORD_ERROR(LOG_ERR, "failed on setting up SIGINT signal handler");
        return -1;
    }
    return 0;
}

int signalhandling_setup_handler(int sig,
                                 signalhandling_handler_callable handler_func) {
    struct sigaction sigact;
    memset(&sigact, 0, sizeof(sigact));
    sigact.sa_handler = handler_func;
    sigact.sa_flags = SA_RESTART;
    if (0 != sigaction(sig, &sigact, NULL)) {
        RECORD_ERROR(LOG_ERR,
                     "failed on setting up SIG%s signal handler",
                     strsignal(sig));
        return -1;
    }
    return 0;
}

int signalhandling_setup_handler_with_flags(
        int sig,
        signalhandling_handler_callable handler_func,
        int sa_flags) {
    struct sigaction sigact;
    memset(&sigact, 0, sizeof(sigact));
    sigact.sa_handler = handler_func;
    sigact.sa_flags = sa_flags;
    if (0 != sigaction(sig, &sigact, NULL)) {
        RECORD_ERROR(LOG_ERR,
                     "failed on setting up SIG%s signal handler",
                     strsignal(sig));
        return -1;
    }
    return 0;
}
