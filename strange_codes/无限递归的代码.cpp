void a();
void b();
void c();
void d();

void a()
{
    c();
}
void b()
{
    a();
}
void c()
{
    d();
}
void d()
{
    b();
}