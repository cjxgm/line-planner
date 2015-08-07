#pragma once

namespace mixin
{
	struct no_copy_ctor
	{
		no_copy_ctor() = default;
		no_copy_ctor(no_copy_ctor const&) = delete;
	};
	struct no_move_ctor
	{
		no_move_ctor() = default;
		no_move_ctor(no_move_ctor &&) = delete;
	};
	struct no_copy_assign
	{
		no_copy_assign& operator = (no_copy_assign const&) = delete;
	};
	struct no_move_assign
	{
		no_move_assign& operator = (no_move_assign &&) = delete;
	};

	struct non_copyable : no_copy_ctor, no_copy_assign {};
	struct non_movable  : no_move_ctor, no_move_assign {};
	struct non_transferable : non_copyable, non_movable {};
}

