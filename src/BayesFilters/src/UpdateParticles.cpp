#include <BayesFilters/UpdateParticles.h>

#include <cmath>
#include <utility>

using namespace bfl;
using namespace Eigen;


UpdateParticles::UpdateParticles() noexcept { }


UpdateParticles::~UpdateParticles() noexcept { }


void UpdateParticles::correctStep(const Ref<const MatrixXf>& pred_states, const Ref<const VectorXf>& pred_weights,
                                  Ref<MatrixXf> cor_states, Ref<VectorXf> cor_weights)
{
    bool valid_buffered_measurement = process_->bufferProcessData();

    if (valid_buffered_measurement)
        std::tie(valid_likelihood_, likelihood_) = likelihood_model_->likelihood(*process_, *measurement_model_, pred_states);

    cor_states = pred_states;
    cor_weights = pred_weights;

    if (valid_likelihood_)
        cor_weights = cor_weights.cwiseProduct(likelihood_);
}


std::pair<bool, VectorXf> UpdateParticles::getLikelihood()
{
    return std::make_pair(valid_likelihood_, likelihood_);
}


void UpdateParticles::setLikelihoodModel(std::unique_ptr<LikelihoodModel> likelihood_model)
{
    likelihood_model_ = std::move(likelihood_model);
}


void UpdateParticles::setMeasurementModel(std::unique_ptr<MeasurementModel> measurement_model)
{
    measurement_model_ = std::move(measurement_model);
}


void UpdateParticles::setProcess(std::unique_ptr<Process> process)
{
    process_ = std::move(process);
}


LikelihoodModel& UpdateParticles::getLikelihoodModel()
{
    return *likelihood_model_;
}


MeasurementModel& UpdateParticles::getMeasurementModel()
{
    return *measurement_model_;
}


Process& UpdateParticles::getProcess()
{
    return *process_;
}
