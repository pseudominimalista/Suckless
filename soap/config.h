/* See LICENSE file for copyright and license details. */

static const Pair pairs[] = {
	/* regex                  action */
	{ "\\.(txt|md|xml|html|toml|yaml|h|c|ms|csv|el|lisp|sh|bash)$", "st vim %s"},
	{ "\\.(mp3|flac|wav|m4a|alac|webm|mp4|mkv|3gb|avi|wma|aac|mov|opus|ogg|gif)$", "ffplay %s" },
	{ "\\.(jpg|jpeg|png|ff)$", "sxiv %s"},
	{ "\\.slide$", "sent %s"},
	{ "\\.pdf$", "mupdf %s"},
};
