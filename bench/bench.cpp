#include <benchmark/benchmark.h>
#include <crtp.hpp>
#include <poly.hpp>
#include <crtp_concept.hpp>
#include <variant>

static void Benchmark_DYNAMIC(benchmark::State& state)
{
	poly::WidgetVector widgets;
	widgets.reserve(4);
	widgets.emplace_back(new poly::HelloWidget{});
	widgets.emplace_back(new poly::WorldWidget{});
	widgets.emplace_back(new poly::SquareWidget{});
	widgets.emplace_back(new poly::OneWidget{});

	uint64_t val = 0;
	for (auto _ : state) {
		poly::processWidgets(widgets, val);
	}
}
BENCHMARK(Benchmark_DYNAMIC);

static void Benchmark_CRTP(benchmark::State& state)
{
	crtp::WidgetVector widgets;
	widgets.reserve(4);
	widgets.emplace_back(crtp::HelloWidget{});
	widgets.emplace_back(crtp::WorldWidget{});
	widgets.emplace_back(crtp::SquareWidget{});
	widgets.emplace_back(crtp::OneWidget{});

	uint64_t val = 0;
	for (auto _ : state) {
		crtp::processWidgets(widgets, val);
	}
}
BENCHMARK(Benchmark_CRTP);


static void Benchmark_CRTP_CONCEPT(benchmark::State& state)
{
	crtp_concept::WidgetVector widgets;
	widgets.reserve(4);
	widgets.emplace_back(crtp_concept::HelloWidget{});
	widgets.emplace_back(crtp_concept::WorldWidget{});
	widgets.emplace_back(crtp_concept::SquareWidget{});
	widgets.emplace_back(crtp_concept::OneWidget{});

	uint64_t val = 0;
	for (auto _ : state) {
		crtp_concept::processWidgets(widgets, val);
	}
}
BENCHMARK(Benchmark_CRTP_CONCEPT);


// Run the benchmark
BENCHMARK_MAIN();