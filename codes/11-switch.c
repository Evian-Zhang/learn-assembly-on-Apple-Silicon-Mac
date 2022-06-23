extern void foo0();
extern void foo1();
extern void foo2();
extern void foo3();

void switch_pattern(int a) {
    switch (a) {
        case 0: foo0(); break;
        case 1: foo1(); break;
        case 2: foo2(); break;
        case 3: foo3(); break;
    }
}
