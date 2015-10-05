#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void print_usage(char *name) {
    printf("Syntax:\n");
    printf("\t%s <hostname> -a \'<Author Name>\' \'<Paper title>\' <file>\n", name);
    printf("\t\tAdd an article\n\n");
    printf("\t%s <hostname> -f <document number>\n", name);
    printf("\t\tFetch an article\n\n");
    printf("\t%s <hostname> -i <document number>\n", name);
    printf("\t\tGet article information\n\n");
    printf("\t%s <hostname> -r <document number>\n", name);
    printf("\t\tRemove an article\n\n");
    printf("\t%s <hostname> -l \n", name);
    printf("\t%s [-h]\n", name);
    printf("\t\tPrint usage syntax\n\n");

    return;
}

void add_article(char *author, char *title, char *filename) {
    return;
}

void fetch_article(char *article) {
    return;
}

void remove_article(char *article) {
    return;
}

void article_info(char *article) {
    return;
}

int main(int argc, char **argv) {
    int c, err;
    char *farg, *iarg, *rarg;
    char *hostname;
    int hflag = 0, aflag = 0, fflag = 0, iflag = 0, rflag = 0, lflag = 0; 
    struct hostent *h;


    while ((c = getopt(argc, argv, "haf:i:r:l")) != -1) {
        switch (c) {
        case 'h':
            hflag = 1;
            break;
        case 'a':
            aflag = 1;
            break;
        case 'f':
            farg = optarg;
            fflag = 1;
            break;
        case 'i':
            iarg = optarg;
            iflag = 1;
            break;
        case 'r':
            rarg = optarg;
            rflag = 1;
            break;
        case 'l':
            lflag = 1;
            break;
        case '?':
            err = 1;
            break;
        }      
    }

    if (hflag == 1 || argc < 2) {
        print_usage(argv[0]);
    }

    if ((argc - optind) < 1) {
        printf("hostname missing!\n");
        print_usage(argv[0]);
        exit(1);
    }
    else {
        hostname = argv[optind];
        h = gethostbyname(hostname);
        if (h == NULL) {
            fprintf(stderr, "Hostname \"%s\" could not be resolved\n", hostname);
            exit(-2);
        }
        // printf(hostname);
    }

    if (aflag == 1) {
        if ((argc - optind) != 4) {
            printf("Incorrect amount of arguments passed!\n");
            print_usage(argv[0]);
        }
        else {
            add_article(argv[optind+1], argv[optind+2],argv[optind+3]);
        }
    }

    if (fflag == 1) {
        printf("farg: %s\n", farg);
        fetch_article(farg);
    }

    if (rflag == 1) {
        printf("rarg: %s\n", rarg);
        remove_article(rarg);
    }

    if (iflag == 1) {
        printf("iarg: %s\n", iarg);
        article_info(iarg);
    }

    printf("optind: %d\n", optind);
    int i;
    for (i = 0; i < argc; i++) {
        printf("%s ", argv[i]);
    }
    printf("\n");




    return 0;
}