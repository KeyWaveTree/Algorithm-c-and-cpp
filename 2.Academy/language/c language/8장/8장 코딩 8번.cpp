#include<stdio.h>
#include<math.h>

void quad_eqn(int a, int b, int c)
{
	double d, x1, x2;

	//�и� ��Ʈ �� ��
	d = b * b - 4.0 * a * c; //int �� ����

	if (d == 0)
	{
		printf("\n");
	}
	else if (d > 0)
	{
		x1 = (-b + sqrt(d)) / (2.0 * a);
		x2 = (-b - sqrt(d)) / (2.0 * a);
		printf("ù��° %f\n", x1);
		printf("�ι�° %f\n", x2);
	}
	else printf("����� �Դϴ�.\n");
	return;
}

int main()
{
	int a, b, c; 
	scanf("%d %d %d", &a, &b, &c);

	quad_eqn(a, b, c);

}