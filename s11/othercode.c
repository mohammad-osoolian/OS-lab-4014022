#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/list.h>
#include <linux/types.h>
#include <linux/slab.h>

struct birthday{
    int day;
    int month;
    int year;
    struct list_head list;
};

static LIST_HEAD(birthday_list);

int simple_init(void){
    struct birthday *p1;
    struct birthday *p2;
    struct birthday *p3;
    struct birthday *p4;
    struct birthday *p5;
    struct birthday *ptr;

    printk(KERN_INFO "Loading Module Birthday...\n");

    p1 = kmalloc(sizeof(*p1), GFP_KERNEL);
    p1->day = 27;
    p1->month = 3;
    p1->year = 1382;
    INIT_LIST_HEAD(&p1->list);
    list_add_tail(&p1->list, &birthday_list);

    p2 = kmalloc(sizeof(*p2), GFP_KERNEL);
    p2->day = 26;
    p2->month = 3;
    p2->year = 1382;
    INIT_LIST_HEAD(&p2->list);
    list_add_tail(&p2->list, &birthday_list);
    
    p3 = kmalloc(sizeof(*p3), GFP_KERNEL);
    p3->day = 25;
    p3->month = 3;
    p3->year = 1382;
    INIT_LIST_HEAD(&p3->list);
    list_add_tail(&p3->list, &birthday_list);
    
    p4 = kmalloc(sizeof(*p4), GFP_KERNEL);
    p4->day = 24;
    p4->month = 3;
    p4->year = 1382;
    INIT_LIST_HEAD(&p4->list);
    list_add_tail(&p4->list, &birthday_list);
    
    p5 = kmalloc(sizeof(*p5), GFP_KERNEL);
    p5->day = 23;
    p5->month = 3;
    p5->year = 1382;
    INIT_LIST_HEAD(&p5->list);
    list_add_tail(&p5->list, &birthday_list);

    list_for_each_entry(ptr, &birthday_list, list){
        printk(KERN_INFO "%d/%d/%d\n", ptr->day, ptr->month, ptr->year);
    }
    
    return 0;
}

void simple_exit(void){
    struct birthday *ptr, *next;
    printk(KERN_INFO "Removig Module Birthday...\n");
    list_for_each_entry_safe(ptr, next, &birthday_list, list){
        printk(KERN_INFO "Removing Birthday: %d/%d/%d\n", ptr->day, ptr->month, ptr->year);
        list_del(&ptr->list);
        kfree(ptr);
    }
}

module_init(simple_init);
module_exit(simple_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");

