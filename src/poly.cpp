#include "../include/poly.hpp"

namespace poly
{
	void poly::HelloWidget::draw() noexcept
	{
		printf("Hello\n");
	}

	uint64_t poly::HelloWidget::compute(uint64_t value) noexcept
	{
		return value++;
	}

	void poly::WorldWidget::draw() noexcept
	{
		printf("World\n");
	}

	uint64_t poly::WorldWidget::compute(uint64_t value) noexcept
	{
		return value += 2;
	}

	void poly::SquareWidget::draw() noexcept
	{
		printf("Square\n");
	}

	uint64_t poly::SquareWidget::compute(uint64_t value) noexcept
	{
		return value * value;
	}

	void poly::OneWidget::draw() noexcept
	{
		printf("One\n");
	}

	uint64_t poly::OneWidget::compute(uint64_t value) noexcept
	{
		return 1;
	}
}