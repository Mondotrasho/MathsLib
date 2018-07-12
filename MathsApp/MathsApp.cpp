#include "Utility.h"
#include <iostream>
#include <iostream>
#include <chrono>
#include <thread>
#include "Vector3.h"
#include "Vector2.h"

typedef std::chrono::high_resolution_clock Clock;

using namespace std::chrono;

void print(float pos)
{
	if (pos > 600) { pos -= 600; }
	if (pos > 400) { pos -= 400; }
	if (pos > 200) { pos -= 200; }

	for (int i = 0; i < pos; ++i)
	{
		std::cout << "-";
	}
	std::cout << "o" << std::endl;
}

void printVec(const Vector3& Vector3)
{
	std::cout << " position : " << Vector3.position << std::endl;
	std::cout << " velocity : " << Vector3.velocity << std::endl;
	std::cout << " acceleration : " << Vector3.acceleration << std::endl;
};

//void printall();

int main()
{
/*
		𝒗 = 𝒖 + 𝒂𝒕
		Find the new velocity using current velocity, acceleration and time

		u - the initial velocity
		v - the final velocity
		a - the acceleration
		s - the displacement
		t - the time*/

	Clock::time_point delta;
	auto current_time = Clock::now();
	auto previous_time = Clock::now();

	Vector3 pos_vel_acc(  0 , 1 , 0.5 );
		while (true) {
			
			
			current_time = Clock::now();
			const auto deltatime = duration_cast<nanoseconds>(current_time - previous_time).count();
			std::cout << " Delta : " << duration_cast<nanoseconds>(current_time - previous_time).count() << " seconds" << std::endl;
			//update
			pos_vel_acc.velocity += pos_vel_acc.acceleration * deltatime;
			
			
			pos_vel_acc.position += pos_vel_acc.velocity * deltatime;
			
			//draw

			
			printVec(pos_vel_acc);
			print(pos_vel_acc.position);
			//printall();
			//system("cls");
			previous_time = current_time;

			Vector2 box{ 1 , 100 };




		}
	
	


/*
	set currentTime to current system time
		set previousTime to currentTime
		set deltaTime to 0
		WHILE game is running
		set currentTime to current system time
		deltaTime = currentTime - previousTime
		update game
		draw game
		previousTime = currentTime
		ENDWHILE*/


	/*set initial position, velocity, and acceleration
		FOR each frame
		compute current acceleration
		compute deltatime
		velocity += acceleration * deltatime
		position += velocity * deltatime
		END FOR
*/
	//std::cout << add(10, 5) << std::endl;
	system("pause");
	return 0;
}
