/*
 *   This file is part of nftlb, nftables load balancer.
 *
 *   Copyright (C) ZEVENET SL.
 *   Author: Laura Garcia <laura.garcia@zevenet.com>
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU Affero General Public License as
 *   published by the Free Software Foundation, either version 3 of the
 *   License, or any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU Affero General Public License for more details.
 *
 *   You should have received a copy of the GNU Affero General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef _OBJECTS_H_
#define _OBJECTS_H_

#define DEFAULT_NAME		""
#define DEFAULT_FQDN		""
#define DEFAULT_IFNAME		NULL
#define DEFAULT_IFIDX		-1
#define DEFAULT_ETHADDR		NULL
#define DEFAULT_VIRTADDR	""
#define DEFAULT_VIRTPORTS	""
#define DEFAULT_IPADDR		NULL
#define DEFAULT_SRCADDR		NULL
#define DEFAULT_PORTS		""
#define DEFAULT_FAMILY		VALUE_FAMILY_IPV4
#define DEFAULT_MODE		VALUE_MODE_SNAT
#define DEFAULT_PROTO		VALUE_PROTO_TCP
#define DEFAULT_SCHED		VALUE_SCHED_RR
#define DEFAULT_HELPER		VALUE_HELPER_NONE
#define DEFAULT_LOG			VALUE_LOG_NONE
#define DEFAULT_MARK		0x0
#define DEFAULT_WEIGHT		1
#define DEFAULT_PRIORITY	1
#define DEFAULT_FARM_STATE	VALUE_STATE_UP
#define DEFAULT_BACKEND_STATE	VALUE_STATE_UP
#define DEFAULT_ACTION		ACTION_START
#define DEFAULT_NEW_RATE_LIMIT_SADDR		0
#define DEFAULT_NEW_RATE_LIMIT_BURST_SADDR	0
#define DEFAULT_RST_LIMIT_BURST_SADDR	0
#define DEFAULT_EST_LIMIT_SADDR	0
#define DEFAULT_TCP_STRICT VALUE_TCPSTRICT_OFF
#define DEFAULT_POLICY_TYPE	VALUE_TYPE_BLACK
#define DEFAULT_POLICY_TIMEOUT	0
#define DEFAULT_POLICY_PRIORITY	-1
#define DEFAULT_TIME		NULL

enum levels {
	LEVEL_INIT,
	LEVEL_FARMS,
	LEVEL_BCKS,
	LEVEL_FARMPOLICY,
	LEVEL_POLICIES,
	LEVEL_ELEMENTS
};

enum keys {
	KEY_FARMS,
	KEY_NAME,
	KEY_NEWNAME,
	KEY_FQDN,
	KEY_IFACE,
	KEY_OFACE,
	KEY_FAMILY,
	KEY_ETHADDR,
	KEY_VIRTADDR,
	KEY_VIRTPORTS,
	KEY_IPADDR,
	KEY_SRCADDR,
	KEY_PORTS,
	KEY_MODE,
	KEY_PROTO,
	KEY_SCHED,
	KEY_HELPER,
	KEY_LOG,
	KEY_MARK,
	KEY_STATE,
	KEY_BCKS,
	KEY_FPOLICIES,
	KEY_WEIGHT,
	KEY_PRIORITY,
	KEY_ACTION,
	KEY_NEW_RATE_LIMIT_SADDR,
	KEY_NEW_RATE_LIMIT_BURST_SADDR,
	KEY_RST_RATE_LIMIT_SADDR,
	KEY_EST_CONN_LIMIT_SADDR,
	KEY_TCP_STRICT,
	KEY_TYPE,
	KEY_TIMEOUT,
	KEY_DATA,
	KEY_TIME
};

enum actions {
	ACTION_START,
	ACTION_STOP,
	ACTION_RELOAD,
	ACTION_DELETE,
	ACTION_NONE,
};

struct obj_config {
	struct farm			*fptr;
	struct backend		*bptr;
	struct policy		*pptr;
	struct element		*eptr;
	struct farmpolicy	*fpptr;
	struct config_pair	*c;
};

void objects_init(void);
struct list_head * obj_get_farms(void);
struct list_head * obj_get_policies(void);
int obj_get_total_farms(void);
int obj_get_total_policies(void);
void obj_set_total_farms(int new_value);
void obj_set_total_policies(int new_value);
int obj_get_dsr_counter(void);
void obj_set_dsr_counter(int new_value);

struct obj_config * obj_get_current_object(void);

char * obj_print_family(int family);
char * obj_print_mode(int mode);
char * obj_print_proto(int protocol);
char * obj_print_sched(int scheduler);
char * obj_print_helper(int helper);
void obj_print_log(int log, char *buf);
char * obj_print_state(int state);
int obj_set_attribute(struct config_pair *c, int actionable);
int obj_set_attribute_string(char *src, char **dst);
void obj_print(void);
int obj_rulerize(void);

char * obj_print_policy_type(int type);

#endif /* _OBJECTS_H_ */
