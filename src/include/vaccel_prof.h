/*
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include <stdbool.h>
#include <stddef.h>

#include "error.h"

#ifdef __cplusplus
extern "C" {
#endif

struct prof_sample;

struct vaccel_prof_region {
	/* Name of the region */
	const char *name;

	/* 'true' if we own the memory of 'name' */
	bool name_owned;

	/* Number of collected samples */
	size_t nr_entries;

	/* Array of collected samples */
	struct prof_sample *samples;

	/* Allocated size for the array */
	size_t size;
};

#define VACCEL_PROF_REGION_INIT(name) { (name), false, 0, NULL, 0 }

bool vaccel_prof_enabled(void);

/* Start profiling a region */
int vaccel_prof_region_start(struct vaccel_prof_region *region);

/* Stop profiling a region */
int vaccel_prof_region_stop(const struct vaccel_prof_region *region);

/* Dump profiling results of a region */
int vaccel_prof_region_print(const struct vaccel_prof_region *region);

/* Initialize a profiling region */
int vaccel_prof_region_init(
	struct vaccel_prof_region *region,
	const char *name
);

/* Destroy a profiling region */
int vaccel_prof_region_destroy(struct vaccel_prof_region *region);

#ifdef __cplusplus
}
#endif
