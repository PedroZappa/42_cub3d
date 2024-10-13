/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   001_test_funkz.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 09:16:16 by passunca          #+#    #+#             */
/*   Updated: 2024/10/13 09:16:17 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests/test_syscallz.h"

int	g_malloc_call_ctr = 0;
int	g_free_call_ctr = 0;
int	g_open_call_ctr = 0;
int	g_close_call_ctr = 0;

bool	fail_check(const char *fail_env, int call_counter)
{
	const char	*sys_count_env = getenv(fail_env);

	if (sys_count_env && (atoi(sys_count_env) == call_counter))
		return (true);
	return (false);
}

void	*z_malloc(size_t size)
{
	++g_malloc_call_ctr;
	if (fail_check("MALLOC_FAIL", g_malloc_call_ctr))
		return (NULL);
	return (malloc(size));
}

void	z_free(void *ptr)
{
	++g_free_call_ctr;
	if (!fail_check("FREE_FAIL", g_free_call_ctr))
		free(ptr);
}

int	z_open(const char *pathname, int flags)
{
	++g_open_call_ctr;
	if (fail_check("OPEN_FAIL", g_open_call_ctr))
		return (-1);
	return (open(pathname, flags));
}

int	z_close(int fd)
{
	++g_close_call_ctr;
	if (fail_check("CLOSE_FAIL", g_close_call_ctr))
		return (-1);
	return (close(fd));
}

#define malloc z_malloc
#define free z_free
#define open z_open
#define close z_close
