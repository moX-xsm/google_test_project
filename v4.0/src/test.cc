#include<mytest/test.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<mytest/linklist.h>
int func_cnt = 0;
struct Function func_head, *func_tail = &func_head;
struct FunctionInfo info;
int RUN_ALL_TESTS(){
    for(struct LinkNode *p = func_head.p.next; p; p = p->next){
        struct Function *func = Head(p, struct Function, p);
        printf(GREEN("[====RUN====]")RED_HL(" %s\n"), func->str);
        info.total = info.success = 0;
        func->func();
        double rate = 100.0 * info.success / info.total;
        printf(GREEN("[  "));
        if(rate == 100.0){
            printf(BLUE_HL("%6.2lf%%"), rate);
        }else {
            printf(RED_HL("%6.2lf%%"), rate);
        }
        printf(GREEN("  ]"));
        printf(" total = %d, success = %d\n", info.total, info.success);

    }
    return 0;
}

void add_function(TestFuncT func, const char *str){
    struct Function *tmp = (struct Function *)calloc(1, sizeof(struct Function));
    tmp->func = func;
    tmp->str = strdup(str);
    func_tail->p.next = &(tmp->p);
    func_tail = tmp;
    return ;
}
