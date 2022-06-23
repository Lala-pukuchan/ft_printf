
# include "ft_printf.h"

int main(void)
{
	char	*p;

	p = "address";
	printf("\n========= c =========\n");
	printf("--- ft_printf ---\n");
	int r_ft_c = ft_printf("%c", 'a');
	printf("\nr_ft = %d\n", r_ft_c);
	printf("--- printf ---\n");
	int r_c = printf("%c", 'a');
	printf("\nr = %d\n", r_c);

	printf("--- ft_printf ---\n");
	int r_ft_c_1 = ft_printf(" %c ", 'a');
	printf("\nr_ft_1 = %d\n", r_ft_c_1);
	printf("--- printf ---\n");
	int r_c_1 = printf(" %c ", 'a');
	printf("\nr_1 = %d\n", r_c_1);

	printf("--- ft_printf ---\n");
	int r_ft_c_2 = ft_printf("%c", NULL);
	printf("\nr_ft_2 = %d\n", r_ft_c_2);
	printf("--- printf ---\n");
	int r_c_2 = printf("%c", NULL);
	printf("\nr_2 = %d\n", r_c_2);
	
	printf("\n========= s =========\n");
	printf("--- ft_printf ---\n");
	int r_ft_s = ft_printf("%s", "test");
	printf("\nr_ft = %d\n", r_ft_s);
	printf("--- printf ---\n");
	int r_s = printf("%s", "test");
	printf("\nr_ft = %d\n", r_s);


	printf("--- ft_printf ---\n");
	int r_ft_s_1 = ft_printf("%s", NULL);
	printf("\nr_ft_1 = %d\n", r_ft_s_1);
	printf("--- printf ---\n");
	int r_s_1 = printf("%s", NULL);
	printf("\nr_ft_1 = %d\n", r_s_1); // 出力値: (null)

	printf("\n========= d =========\n");
	printf("--- ft_printf ---\n");
	int r_ft_d = ft_printf("%d", 1);
	printf("\nr_ft = %d\n", r_ft_d);
	printf("--- printf ---\n");
	int r_d = ft_printf("%d", 1);
	printf("\nr_ft = %d\n", r_d);

	printf("\n========= p =========\n");
	printf("--- ft_printf ---\n");
	int r_ft_p = ft_printf("%p", p);
	printf("\nr_ft = %d\n", r_ft_p);
	printf("--- printf ---\n");
	int r_p = printf("%p", p);
	printf("\nr = %d\n", r_p);

	printf("--- ft_printf ---\n");
	int a = 0;
	int r_ft_p_1 = ft_printf(" %p %p ", NULL, NULL);
	printf("\nr_ft_1 = %d\n", r_ft_p_1);
	printf("--- printf ---\n");
	int r_p_1 = printf(" %p %p ", NULL, NULL);
	printf("\nr_1 = %d\n", r_p_1);

	printf("\n========= i =========\n");
	printf("--- ft_printf ---\n");
	int r_ft_i = ft_printf("%i", 12);
	printf("\nr_ft = %i\n", r_ft_i);
	printf("--- printf ---\n");
	int r_i = printf("%i", 12);
	printf("\nr = %d\n", r_i);

	printf("\n========= u =========\n");
	printf("--- ft_printf ---\n");
	int r_ft_u = ft_printf("%u", 24);
	printf("\nr_ft = %i\n", r_ft_u);
	printf("--- printf ---\n");
	// [] To Do: printfにintの最大値を超えたものを入れると、%ldに変更するようにwarningが出て実行できない。
	int r_u = printf("%u", 24);
	printf("\nr = %d\n", r_u);

	printf("\n========= x =========\n");
	printf("--- ft_printf ---\n");
	int r_ft_x = ft_printf("%x", 12);
	printf("\nr_ft = %i\n", r_ft_x);
	printf("--- printf ---\n");
	int r_x = printf("%x", 12);
	printf("\nr = %d\n", r_x);

	printf("--- ft_printf ---\n");
	int r_ft_x_1 = ft_printf("%x", LONG_MAX);
	printf("\nr_ft_1 = %i\n", r_ft_x);
	printf("--- printf ---\n");
	// 出力値は、ffffffff: 4294967295 (unsigned intの最大値に当たる)
	int r_x_1 = printf("%x", LONG_MAX);
	printf("\nr_1 = %d\n", r_x);

	printf("\n========= X =========\n");
	printf("--- ft_printf ---\n");
	int r_ft_X = ft_printf("%X", 12);
	printf("\nr_ft = %i\n", r_ft_X);
	printf("--- printf ---\n");
	int r_X = printf("%X", 12);
	printf("\nr = %d\n", r_X);

	return (0);
}
