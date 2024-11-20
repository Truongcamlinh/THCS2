#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct
{
    int ma;
    char ten[101];
    char ngay_sinh[11];
    float diem1, diem2, diem3;
    float tong_diem;
} ThiSinh;

int main()
{
    int n;
    ThiSinh ds[MAX];

    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++)
    {
        ds[i].ma = i + 1;
        fgets(ds[i].ten, sizeof(ds[i].ten), stdin);
        ds[i].ten[strcspn(ds[i].ten, "\n")] = '\0';

        fgets(ds[i].ngay_sinh, sizeof(ds[i].ngay_sinh), stdin);
        ds[i].ngay_sinh[strcspn(ds[i].ngay_sinh, "\n")] = '\0';

        scanf("%f %f %f", &ds[i].diem1, &ds[i].diem2, &ds[i].diem3);
        getchar();

        ds[i].tong_diem = ds[i].diem1 + ds[i].diem2 + ds[i].diem3;
    }

    float diem_cao_nhat = 0;
    for (int i = 0; i < n; i++)
    {
        if (ds[i].tong_diem > diem_cao_nhat)
            diem_cao_nhat = ds[i].tong_diem;
    }

    for (int i = 0; i < n; i++)
    {
        if (ds[i].tong_diem == diem_cao_nhat)
            printf("%d %s %s %.1f\n", ds[i].ma, ds[i].ten, ds[i].ngay_sinh, ds[i].tong_diem);
    }
}
