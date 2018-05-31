#include "stubctl.h"

#include <stdlib.h>

extern int install_stub_driver(const char *id_hw);
extern int uninstall_stub_driver(const char *id_hw);

const char	*id_hw_arg;

typedef enum {
	MODE_NONE,
	MODE_INSTALL,
	MODE_UNINSTALL,
} mode_t;

static mode_t	mode = MODE_NONE;

static void
stubctl_usage(void)
{
	printf(
"stubctl --install/-i [id hw]\n"
"        --uninstall/-u [hw id]\n"
	);
}

static void
parse_args(int argc, char *argv[])
{
	const struct option opts[] = {
		{ "install", no_argument, NULL, 'i' },
		{ "uninstall", no_argument, NULL, 'u' },
		{ "help", no_argument, NULL, 'h' },
		{ NULL, 0, NULL, 0 }
	};
	int	c;

	for (;;) {
		c = getopt_long(argc, argv, "iu", opts, NULL);

		if (c == -1)
			break;

		switch (c) {
		case 'i':
			mode = MODE_INSTALL;
			break;
		case 'u':
			mode = MODE_UNINSTALL;
			break;
		case 'h':
			stubctl_usage();
			exit(0);
			break;
		case '?':
			err("stubctl: invalid option\n");
			/* fall through */
		default:
			stubctl_usage();
			exit(1);
		}
	}
	id_hw_arg = argv[optind];
}

int
main(int argc, char *argv[])
{
	parse_args(argc, argv);

	usbip_use_stderr = 1;

	switch (mode) {
	case MODE_INSTALL:
		return install_stub_driver(id_hw_arg);
	case MODE_UNINSTALL:
		return uninstall_stub_driver(id_hw_arg);
	default:
		stubctl_usage();
		return 1;
	}
	return 0;
}