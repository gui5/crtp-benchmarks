
#include <gtest/gtest.h>
#include <crtp.hpp>
#include <poly.hpp>
#include <crtp_concept.hpp>
#include <sstream>

TEST(BenchmarkTest, ComputeIsSame)
{

	std::unique_ptr<poly::IWidget> polyHelloWidget = std::make_unique<poly::HelloWidget>();
	std::unique_ptr<poly::WorldWidget> polyWorldWidget = std::make_unique<poly::WorldWidget>();
	std::unique_ptr<poly::SquareWidget> polySquareWidget = std::make_unique<poly::SquareWidget>();
	std::unique_ptr<poly::IWidget> polyOneWidget = std::make_unique<poly::OneWidget>();

	crtp::HelloWidget crtpHelloWidget;
	crtp::WorldWidget crtpWorldWidget;
	crtp::SquareWidget crtpSquareWidget;
	crtp::OneWidget crtpOneWidget;

	crtp_concept::HelloWidget conceptHelloWidget;
	crtp_concept::WorldWidget conceptWorldWidget;
	crtp_concept::SquareWidget conceptSquareWidget;
	crtp_concept::OneWidget conceptOneWidget;


	uint64_t input_value = 2;

	auto polyHelloWidgetOut = polyHelloWidget->compute(input_value);
	auto polyWorldWidgetOut = polyWorldWidget->compute(input_value);
	auto polySquareWidgetOut = polySquareWidget->compute(input_value);
	auto polyOneWidgetOut = polyOneWidget->compute(input_value);

	auto crtpHelloWidgetOut = crtpHelloWidget.compute(input_value);
	auto crtpWorldWidgetOut = crtpWorldWidget.compute(input_value);
	auto crtpSquareWidgetOut = crtpSquareWidget.compute(input_value);
	auto crtpOneWidgetOut = crtpOneWidget.compute(input_value);

	auto conceptHelloWidgetOut = conceptHelloWidget.compute(input_value);
	auto conceptWorldWidgetOut = conceptWorldWidget.compute(input_value);
	auto concepSquareWidgetOut = conceptSquareWidget.compute(input_value);
	auto conceptOneWidgetOut = conceptOneWidget.compute(input_value);

	ASSERT_EQ(polyHelloWidgetOut, crtpHelloWidgetOut);
	ASSERT_EQ(polyWorldWidgetOut, crtpWorldWidgetOut);
	ASSERT_EQ(polySquareWidgetOut, crtpSquareWidgetOut);
	ASSERT_EQ(polyOneWidgetOut, crtpOneWidgetOut);

	ASSERT_EQ(polyHelloWidgetOut, conceptHelloWidgetOut);
	ASSERT_EQ(polyWorldWidgetOut, conceptWorldWidgetOut);
	ASSERT_EQ(polySquareWidgetOut, concepSquareWidgetOut);
	ASSERT_EQ(polyOneWidgetOut, conceptOneWidgetOut);

}

TEST(BenchmarkTest, DrawIsSame)
{
	std::unique_ptr<poly::IWidget> polyHelloWidget = std::make_unique<poly::HelloWidget>();
	std::unique_ptr<poly::WorldWidget> polyWorldWidget = std::make_unique<poly::WorldWidget>();
	std::unique_ptr<poly::SquareWidget> polySquareWidget = std::make_unique<poly::SquareWidget>();
	std::unique_ptr<poly::IWidget> polyOneWidget = std::make_unique<poly::OneWidget>();

	crtp::HelloWidget crtpHelloWidget;
	crtp::WorldWidget crtpWorldWidget;
	crtp::SquareWidget crtpSquareWidget;
	crtp::OneWidget crtpOneWidget;

	crtp_concept::HelloWidget conceptHelloWidget;
	crtp_concept::WorldWidget conceptWorldWidget;
	crtp_concept::SquareWidget conceptSquareWidget;
	crtp_concept::OneWidget conceptOneWidget;

	int a = 0;



}