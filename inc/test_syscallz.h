/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_funk.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 09:15:38 by passunca          #+#    #+#             */
/*   Updated: 2024/10/13 09:15:55 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_SYSCALLZ_H
# define TEST_SYSCALLZ_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>

# define MALLOC z_malloc
// # define FREE z_free
// # define OPEN z_open
// # define CLOSE z_close

bool	fail_check(const char *fail_env, int call_counter);
void	*z_malloc(size_t size);
void	z_free(void *ptr);
int		z_open(const char *pathname, int flags);
int		z_close(int fd);

extern int	g_malloc_call_ctr;
extern int	g_free_call_ctr;
extern int	g_open_call_ctr;
extern int	g_close_call_ctr;

#endif
