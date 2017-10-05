#include "BayesFilters/VisualCorrectionDecorator.h"

using namespace bfl;
using namespace cv;
using namespace Eigen;


void VisualCorrectionDecorator::correct(Ref<MatrixXf> states, Ref<MatrixXf> weights, cv::InputArray measurements)
{
    visual_correction_->correct(states, weights, measurements);
}


void VisualCorrectionDecorator::innovation(const Ref<const MatrixXf>& states, InputArray measurements, Ref<MatrixXf> innovations)
{
    visual_correction_->innovation(states, measurements, innovations);
}


void VisualCorrectionDecorator::likelihood(const Ref<const MatrixXf>& innovations, Ref<MatrixXf> weights)
{
    visual_correction_->likelihood(innovations, weights);
}


bool VisualCorrectionDecorator::setObservationModelProperty(const std::string& property)
{
    return visual_correction_->setObservationModelProperty(property);
}


void VisualCorrectionDecorator::observe(const Ref<const MatrixXf>& states, cv::OutputArray observations)
{
    return visual_correction_->observe(states, observations);
}


VisualCorrectionDecorator::VisualCorrectionDecorator(std::unique_ptr<AbstractVisualCorrection> visual_correction) noexcept :
    visual_correction_(std::move(visual_correction)) { }


VisualCorrectionDecorator::~VisualCorrectionDecorator() noexcept { }


VisualCorrectionDecorator::VisualCorrectionDecorator(VisualCorrectionDecorator&& visual_correction) noexcept :
    visual_correction_(std::move(visual_correction.visual_correction_)) { }


VisualCorrectionDecorator& VisualCorrectionDecorator::operator=(VisualCorrectionDecorator&& visual_correction) noexcept
{
    visual_correction_ = std::move(visual_correction.visual_correction_);

    return *this;
}
