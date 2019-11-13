classdef AbstractState < SwigRef
  methods
    function delete(self)
      if self.swigInd
        CoolPropMATLAB_wrap(127, self);
        self.swigInd=uint64(0);
      end
    end
    function varargout = set_T(self,varargin)
      [varargout{1:nargout}] = CoolPropMATLAB_wrap(129, self, varargin{:});
    end
    function varargout = backend_name(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(130, self, varargin{:});
    end
    function varargout = using_mole_fractions(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(131, self, varargin{:});
    end
    function varargout = using_mass_fractions(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(132, self, varargin{:});
    end
    function varargout = using_volu_fractions(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(133, self, varargin{:});
    end
    function varargout = update(self,varargin)
      [varargout{1:nargout}] = CoolPropMATLAB_wrap(134, self, varargin{:});
    end
    function varargout = update_with_guesses(self,varargin)
      [varargout{1:nargout}] = CoolPropMATLAB_wrap(135, self, varargin{:});
    end
    function varargout = get_mole_fractions(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(136, self, varargin{:});
    end
    function varargout = available_in_high_level(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(137, self, varargin{:});
    end
    function varargout = fluid_names(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(138, self, varargin{:});
    end
    function varargout = clear(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(139, self, varargin{:});
    end
    function varargout = set_mole_fractions(self,varargin)
      [varargout{1:nargout}] = CoolPropMATLAB_wrap(140, self, varargin{:});
    end
    function varargout = set_mass_fractions(self,varargin)
      [varargout{1:nargout}] = CoolPropMATLAB_wrap(141, self, varargin{:});
    end
    function varargout = set_volu_fractions(self,varargin)
      [varargout{1:nargout}] = CoolPropMATLAB_wrap(142, self, varargin{:});
    end
    function varargout = get_reducing_state(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(143, self, varargin{:});
    end
    function varargout = get_state(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(144, self, varargin{:});
    end
    function varargout = Tmin(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(145, self, varargin{:});
    end
    function varargout = Tmax(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(146, self, varargin{:});
    end
    function varargout = pmax(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(147, self, varargin{:});
    end
    function varargout = Ttriple(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(148, self, varargin{:});
    end
    function varargout = phase(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(149, self, varargin{:});
    end
    function varargout = specify_phase(self,varargin)
      [varargout{1:nargout}] = CoolPropMATLAB_wrap(150, self, varargin{:});
    end
    function varargout = unspecify_phase(self,varargin)
      [varargout{1:nargout}] = CoolPropMATLAB_wrap(151, self, varargin{:});
    end
    function varargout = T_critical(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(152, self, varargin{:});
    end
    function varargout = T_reducing(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(153, self, varargin{:});
    end
    function varargout = p_critical(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(154, self, varargin{:});
    end
    function varargout = rhomolar_critical(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(155, self, varargin{:});
    end
    function varargout = rhomass_critical(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(156, self, varargin{:});
    end
    function varargout = rhomolar_reducing(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(157, self, varargin{:});
    end
    function varargout = rhomass_reducing(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(158, self, varargin{:});
    end
    function varargout = p_triple(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(159, self, varargin{:});
    end
    function varargout = name(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(160, self, varargin{:});
    end
    function varargout = keyed_output(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(161, self, varargin{:});
    end
    function varargout = trivial_keyed_output(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(162, self, varargin{:});
    end
    function varargout = saturated_liquid_keyed_output(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(163, self, varargin{:});
    end
    function varargout = saturated_vapor_keyed_output(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(164, self, varargin{:});
    end
    function varargout = T(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(165, self, varargin{:});
    end
    function varargout = rhomolar(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(166, self, varargin{:});
    end
    function varargout = rhomass(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(167, self, varargin{:});
    end
    function varargout = p(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(168, self, varargin{:});
    end
    function varargout = Q(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(169, self, varargin{:});
    end
    function varargout = tau(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(170, self, varargin{:});
    end
    function varargout = delta(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(171, self, varargin{:});
    end
    function varargout = molar_mass(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(172, self, varargin{:});
    end
    function varargout = acentric_factor(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(173, self, varargin{:});
    end
    function varargout = gas_constant(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(174, self, varargin{:});
    end
    function varargout = Bvirial(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(175, self, varargin{:});
    end
    function varargout = dBvirial_dT(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(176, self, varargin{:});
    end
    function varargout = Cvirial(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(177, self, varargin{:});
    end
    function varargout = dCvirial_dT(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(178, self, varargin{:});
    end
    function varargout = compressibility_factor(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(179, self, varargin{:});
    end
    function varargout = hmolar(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(180, self, varargin{:});
    end
    function varargout = hmass(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(181, self, varargin{:});
    end
    function varargout = smolar(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(182, self, varargin{:});
    end
    function varargout = smass(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(183, self, varargin{:});
    end
    function varargout = umolar(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(184, self, varargin{:});
    end
    function varargout = umass(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(185, self, varargin{:});
    end
    function varargout = cpmolar(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(186, self, varargin{:});
    end
    function varargout = cpmass(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(187, self, varargin{:});
    end
    function varargout = cp0molar(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(188, self, varargin{:});
    end
    function varargout = cp0mass(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(189, self, varargin{:});
    end
    function varargout = cvmolar(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(190, self, varargin{:});
    end
    function varargout = cvmass(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(191, self, varargin{:});
    end
    function varargout = gibbsmolar(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(192, self, varargin{:});
    end
    function varargout = gibbsmass(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(193, self, varargin{:});
    end
    function varargout = speed_sound(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(194, self, varargin{:});
    end
    function varargout = isothermal_compressibility(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(195, self, varargin{:});
    end
    function varargout = isobaric_expansion_coefficient(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(196, self, varargin{:});
    end
    function varargout = fugacity_coefficient(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(197, self, varargin{:});
    end
    function varargout = fugacity(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(198, self, varargin{:});
    end
    function varargout = PIP(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(199, self, varargin{:});
    end
    function varargout = true_critical_point(self,varargin)
      [varargout{1:nargout}] = CoolPropMATLAB_wrap(200, self, varargin{:});
    end
    function varargout = mole_fractions_liquid(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(201, self, varargin{:});
    end
    function varargout = mole_fractions_vapor(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(202, self, varargin{:});
    end
    function varargout = ideal_curve(self,varargin)
      [varargout{1:nargout}] = CoolPropMATLAB_wrap(203, self, varargin{:});
    end
    function varargout = first_partial_deriv(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(204, self, varargin{:});
    end
    function varargout = second_partial_deriv(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(205, self, varargin{:});
    end
    function varargout = first_saturation_deriv(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(206, self, varargin{:});
    end
    function varargout = second_saturation_deriv(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(207, self, varargin{:});
    end
    function varargout = first_two_phase_deriv(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(208, self, varargin{:});
    end
    function varargout = second_two_phase_deriv(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(209, self, varargin{:});
    end
    function varargout = first_two_phase_deriv_splined(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(210, self, varargin{:});
    end
    function varargout = build_phase_envelope(self,varargin)
      [varargout{1:nargout}] = CoolPropMATLAB_wrap(211, self, varargin{:});
    end
    function varargout = get_phase_envelope_data(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(212, self, varargin{:});
    end
    function varargout = has_melting_line(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(213, self, varargin{:});
    end
    function varargout = melting_line(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(214, self, varargin{:});
    end
    function varargout = saturation_ancillary(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(215, self, varargin{:});
    end
    function varargout = viscosity(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(216, self, varargin{:});
    end
    function varargout = conductivity(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(217, self, varargin{:});
    end
    function varargout = surface_tension(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(218, self, varargin{:});
    end
    function varargout = Prandtl(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(219, self, varargin{:});
    end
    function varargout = alpha0(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(220, self, varargin{:});
    end
    function varargout = dalpha0_dDelta(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(221, self, varargin{:});
    end
    function varargout = dalpha0_dTau(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(222, self, varargin{:});
    end
    function varargout = d2alpha0_dDelta2(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(223, self, varargin{:});
    end
    function varargout = d2alpha0_dDelta_dTau(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(224, self, varargin{:});
    end
    function varargout = d2alpha0_dTau2(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(225, self, varargin{:});
    end
    function varargout = d3alpha0_dTau3(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(226, self, varargin{:});
    end
    function varargout = d3alpha0_dDelta_dTau2(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(227, self, varargin{:});
    end
    function varargout = d3alpha0_dDelta2_dTau(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(228, self, varargin{:});
    end
    function varargout = d3alpha0_dDelta3(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(229, self, varargin{:});
    end
    function varargout = alphar(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(230, self, varargin{:});
    end
    function varargout = dalphar_dDelta(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(231, self, varargin{:});
    end
    function varargout = dalphar_dTau(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(232, self, varargin{:});
    end
    function varargout = d2alphar_dDelta2(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(233, self, varargin{:});
    end
    function varargout = d2alphar_dDelta_dTau(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(234, self, varargin{:});
    end
    function varargout = d2alphar_dTau2(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(235, self, varargin{:});
    end
    function varargout = d3alphar_dDelta3(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(236, self, varargin{:});
    end
    function varargout = d3alphar_dDelta2_dTau(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(237, self, varargin{:});
    end
    function varargout = d3alphar_dDelta_dTau2(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(238, self, varargin{:});
    end
    function varargout = d3alphar_dTau3(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(239, self, varargin{:});
    end
    function varargout = d4alphar_dDelta4(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(240, self, varargin{:});
    end
    function varargout = d4alphar_dDelta3_dTau(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(241, self, varargin{:});
    end
    function varargout = d4alphar_dDelta2_dTau2(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(242, self, varargin{:});
    end
    function varargout = d4alphar_dDelta_dTau3(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(243, self, varargin{:});
    end
    function varargout = d4alphar_dTau4(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(244, self, varargin{:});
    end
    function self = AbstractState(varargin)
      if nargin~=1 || ~ischar(varargin{1}) || ~strcmp(varargin{1},'_swigCreate')
        error('No matching constructor');
      end
    end
  end
  methods(Static)
    function varargout = factory(varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(128, varargin{:});
    end
  end
end
