#ifndef WNATARGET_H
#define WNATARGET_H

#include <BayesFilters/MeasurementModelDecorator.h>
#include <BayesFilters/StateModel.h>

namespace bfl {
    class StateModelTargetMeasurement;
}


class bfl::StateModelTargetMeasurement : public MeasurementModelDecorator
{
public:
    StateModelTargetMeasurement(std::unique_ptr<MeasurementModel> measurement_model,
                                std::unique_ptr<StateModel> state_model,
                                const unsigned int simulation_time) noexcept;

    virtual ~StateModelTargetMeasurement() noexcept { };

    std::pair<bool, Eigen::MatrixXf> getMeasurements() override;

protected:
    unsigned int simulation_time_;

    std::unique_ptr<StateModel> state_model_;

    Eigen::MatrixXf target_;

    Eigen::MatrixXf measurement_;
};

#endif /* WNATARGET_H */