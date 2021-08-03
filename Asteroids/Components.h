#pragma once
namespace Components {
	class kinematic
	{
	protected:
		int acceleration,
			speed,
			max_speed,
			friction;

	public:
		void set_kinematic();
		void move();
	};

	class Control
	{
	public:
		Control();
		~Control();

	protected:
		template <typename U, typename D, typename L, typename R>
		struct Movement
		{
			U up;
			D down;
			L left;
			R right;
		};
	};

	class Sound
	{

	};
}