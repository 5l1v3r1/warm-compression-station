classdef PED < SwigRef
  methods
    function varargout = TypeI(self, varargin)
      narginchk(1, 2)
      if nargin==1
        nargoutchk(0, 1)
        varargout{1} = CoolPropMATLAB_wrap(262, self);
      else
        nargoutchk(0, 0)
        CoolPropMATLAB_wrap(263, self, varargin{1});
      end
    end
    function varargout = built(self, varargin)
      narginchk(1, 2)
      if nargin==1
        nargoutchk(0, 1)
        varargout{1} = CoolPropMATLAB_wrap(264, self);
      else
        nargoutchk(0, 0)
        CoolPropMATLAB_wrap(265, self, varargin{1});
      end
    end
    function varargout = iTsat_max(self, varargin)
      narginchk(1, 2)
      if nargin==1
        nargoutchk(0, 1)
        varargout{1} = CoolPropMATLAB_wrap(266, self);
      else
        nargoutchk(0, 0)
        CoolPropMATLAB_wrap(267, self, varargin{1});
      end
    end
    function varargout = ipsat_max(self, varargin)
      narginchk(1, 2)
      if nargin==1
        nargoutchk(0, 1)
        varargout{1} = CoolPropMATLAB_wrap(268, self);
      else
        nargoutchk(0, 0)
        CoolPropMATLAB_wrap(269, self, varargin{1});
      end
    end
    function varargout = icrit(self, varargin)
      narginchk(1, 2)
      if nargin==1
        nargoutchk(0, 1)
        varargout{1} = CoolPropMATLAB_wrap(270, self);
      else
        nargoutchk(0, 0)
        CoolPropMATLAB_wrap(271, self, varargin{1});
      end
    end
    function varargout = T(self, varargin)
      narginchk(1, 2)
      if nargin==1
        nargoutchk(0, 1)
        varargout{1} = CoolPropMATLAB_wrap(272, self);
      else
        nargoutchk(0, 0)
        CoolPropMATLAB_wrap(273, self, varargin{1});
      end
    end
    function varargout = p(self, varargin)
      narginchk(1, 2)
      if nargin==1
        nargoutchk(0, 1)
        varargout{1} = CoolPropMATLAB_wrap(274, self);
      else
        nargoutchk(0, 0)
        CoolPropMATLAB_wrap(275, self, varargin{1});
      end
    end
    function varargout = lnT(self, varargin)
      narginchk(1, 2)
      if nargin==1
        nargoutchk(0, 1)
        varargout{1} = CoolPropMATLAB_wrap(276, self);
      else
        nargoutchk(0, 0)
        CoolPropMATLAB_wrap(277, self, varargin{1});
      end
    end
    function varargout = lnp(self, varargin)
      narginchk(1, 2)
      if nargin==1
        nargoutchk(0, 1)
        varargout{1} = CoolPropMATLAB_wrap(278, self);
      else
        nargoutchk(0, 0)
        CoolPropMATLAB_wrap(279, self, varargin{1});
      end
    end
    function varargout = rhomolar_liq(self, varargin)
      narginchk(1, 2)
      if nargin==1
        nargoutchk(0, 1)
        varargout{1} = CoolPropMATLAB_wrap(280, self);
      else
        nargoutchk(0, 0)
        CoolPropMATLAB_wrap(281, self, varargin{1});
      end
    end
    function varargout = rhomolar_vap(self, varargin)
      narginchk(1, 2)
      if nargin==1
        nargoutchk(0, 1)
        varargout{1} = CoolPropMATLAB_wrap(282, self);
      else
        nargoutchk(0, 0)
        CoolPropMATLAB_wrap(283, self, varargin{1});
      end
    end
    function varargout = lnrhomolar_liq(self, varargin)
      narginchk(1, 2)
      if nargin==1
        nargoutchk(0, 1)
        varargout{1} = CoolPropMATLAB_wrap(284, self);
      else
        nargoutchk(0, 0)
        CoolPropMATLAB_wrap(285, self, varargin{1});
      end
    end
    function varargout = lnrhomolar_vap(self, varargin)
      narginchk(1, 2)
      if nargin==1
        nargoutchk(0, 1)
        varargout{1} = CoolPropMATLAB_wrap(286, self);
      else
        nargoutchk(0, 0)
        CoolPropMATLAB_wrap(287, self, varargin{1});
      end
    end
    function varargout = hmolar_liq(self, varargin)
      narginchk(1, 2)
      if nargin==1
        nargoutchk(0, 1)
        varargout{1} = CoolPropMATLAB_wrap(288, self);
      else
        nargoutchk(0, 0)
        CoolPropMATLAB_wrap(289, self, varargin{1});
      end
    end
    function varargout = hmolar_vap(self, varargin)
      narginchk(1, 2)
      if nargin==1
        nargoutchk(0, 1)
        varargout{1} = CoolPropMATLAB_wrap(290, self);
      else
        nargoutchk(0, 0)
        CoolPropMATLAB_wrap(291, self, varargin{1});
      end
    end
    function varargout = smolar_liq(self, varargin)
      narginchk(1, 2)
      if nargin==1
        nargoutchk(0, 1)
        varargout{1} = CoolPropMATLAB_wrap(292, self);
      else
        nargoutchk(0, 0)
        CoolPropMATLAB_wrap(293, self, varargin{1});
      end
    end
    function varargout = smolar_vap(self, varargin)
      narginchk(1, 2)
      if nargin==1
        nargoutchk(0, 1)
        varargout{1} = CoolPropMATLAB_wrap(294, self);
      else
        nargoutchk(0, 0)
        CoolPropMATLAB_wrap(295, self, varargin{1});
      end
    end
    function varargout = Q(self, varargin)
      narginchk(1, 2)
      if nargin==1
        nargoutchk(0, 1)
        varargout{1} = CoolPropMATLAB_wrap(296, self);
      else
        nargoutchk(0, 0)
        CoolPropMATLAB_wrap(297, self, varargin{1});
      end
    end
    function varargout = K(self, varargin)
      narginchk(1, 2)
      if nargin==1
        nargoutchk(0, 1)
        varargout{1} = CoolPropMATLAB_wrap(298, self);
      else
        nargoutchk(0, 0)
        CoolPropMATLAB_wrap(299, self, varargin{1});
      end
    end
    function varargout = lnK(self, varargin)
      narginchk(1, 2)
      if nargin==1
        nargoutchk(0, 1)
        varargout{1} = CoolPropMATLAB_wrap(300, self);
      else
        nargoutchk(0, 0)
        CoolPropMATLAB_wrap(301, self, varargin{1});
      end
    end
    function varargout = x(self, varargin)
      narginchk(1, 2)
      if nargin==1
        nargoutchk(0, 1)
        varargout{1} = CoolPropMATLAB_wrap(302, self);
      else
        nargoutchk(0, 0)
        CoolPropMATLAB_wrap(303, self, varargin{1});
      end
    end
    function varargout = y(self, varargin)
      narginchk(1, 2)
      if nargin==1
        nargoutchk(0, 1)
        varargout{1} = CoolPropMATLAB_wrap(304, self);
      else
        nargoutchk(0, 0)
        CoolPropMATLAB_wrap(305, self, varargin{1});
      end
    end
    function self = PED(varargin)
      if nargin~=1 || ~ischar(varargin{1}) || ~strcmp(varargin{1},'_swigCreate')
        % How to get working on C side? Commented out, replaed by hack below
        %self.swigInd = CoolPropMATLAB_wrap(306, varargin{:});
        tmp = CoolPropMATLAB_wrap(306, varargin{:}); % FIXME
        self.swigInd = tmp.swigInd;
        tmp.swigInd = uint64(0);
      end
    end
    function varargout = vectors(self, varargin)
      narginchk(1, 2)
      if nargin==1
        nargoutchk(0, 1)
        varargout{1} = CoolPropMATLAB_wrap(307, self);
      else
        nargoutchk(0, 0)
        CoolPropMATLAB_wrap(308, self, varargin{1});
      end
    end
    function varargout = matrices(self, varargin)
      narginchk(1, 2)
      if nargin==1
        nargoutchk(0, 1)
        varargout{1} = CoolPropMATLAB_wrap(309, self);
      else
        nargoutchk(0, 0)
        CoolPropMATLAB_wrap(310, self, varargin{1});
      end
    end
    function varargout = resize(self,varargin)
      [varargout{1:nargout}] = CoolPropMATLAB_wrap(311, self, varargin{:});
    end
    function varargout = clear(self,varargin)
      [varargout{1:nargout}] = CoolPropMATLAB_wrap(312, self, varargin{:});
    end
    function varargout = pack(self,varargin)
      [varargout{1:nargout}] = CoolPropMATLAB_wrap(313, self, varargin{:});
    end
    function varargout = get_vector_iterator(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(314, self, varargin{:});
    end
    function varargout = get_matrix_iterator(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(315, self, varargin{:});
    end
    function varargout = unpack(self,varargin)
      [varargout{1:nargout}] = CoolPropMATLAB_wrap(316, self, varargin{:});
    end
    function varargout = deserialize(self,varargin)
      [varargout{1:nargout}] = CoolPropMATLAB_wrap(317, self, varargin{:});
    end
    function varargout = insert_variables(self,varargin)
      [varargout{1:nargout}] = CoolPropMATLAB_wrap(318, self, varargin{:});
    end
    function varargout = store_variables(self,varargin)
      [varargout{1:nargout}] = CoolPropMATLAB_wrap(319, self, varargin{:});
    end
    function delete(self)
      if self.swigInd
        CoolPropMATLAB_wrap(320, self);
        self.swigInd=uint64(0);
      end
    end
  end
  methods(Static)
  end
end
