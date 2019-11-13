classdef GuessesStructure < SwigRef
  methods
    function varargout = T(self, varargin)
      narginchk(1, 2)
      if nargin==1
        nargoutchk(0, 1)
        varargout{1} = CoolPropMATLAB_wrap(107, self);
      else
        nargoutchk(0, 0)
        CoolPropMATLAB_wrap(108, self, varargin{1});
      end
    end
    function varargout = p(self, varargin)
      narginchk(1, 2)
      if nargin==1
        nargoutchk(0, 1)
        varargout{1} = CoolPropMATLAB_wrap(109, self);
      else
        nargoutchk(0, 0)
        CoolPropMATLAB_wrap(110, self, varargin{1});
      end
    end
    function varargout = rhomolar(self, varargin)
      narginchk(1, 2)
      if nargin==1
        nargoutchk(0, 1)
        varargout{1} = CoolPropMATLAB_wrap(111, self);
      else
        nargoutchk(0, 0)
        CoolPropMATLAB_wrap(112, self, varargin{1});
      end
    end
    function varargout = hmolar(self, varargin)
      narginchk(1, 2)
      if nargin==1
        nargoutchk(0, 1)
        varargout{1} = CoolPropMATLAB_wrap(113, self);
      else
        nargoutchk(0, 0)
        CoolPropMATLAB_wrap(114, self, varargin{1});
      end
    end
    function varargout = smolar(self, varargin)
      narginchk(1, 2)
      if nargin==1
        nargoutchk(0, 1)
        varargout{1} = CoolPropMATLAB_wrap(115, self);
      else
        nargoutchk(0, 0)
        CoolPropMATLAB_wrap(116, self, varargin{1});
      end
    end
    function varargout = rhomolar_liq(self, varargin)
      narginchk(1, 2)
      if nargin==1
        nargoutchk(0, 1)
        varargout{1} = CoolPropMATLAB_wrap(117, self);
      else
        nargoutchk(0, 0)
        CoolPropMATLAB_wrap(118, self, varargin{1});
      end
    end
    function varargout = rhomolar_vap(self, varargin)
      narginchk(1, 2)
      if nargin==1
        nargoutchk(0, 1)
        varargout{1} = CoolPropMATLAB_wrap(119, self);
      else
        nargoutchk(0, 0)
        CoolPropMATLAB_wrap(120, self, varargin{1});
      end
    end
    function varargout = x(self, varargin)
      narginchk(1, 2)
      if nargin==1
        nargoutchk(0, 1)
        varargout{1} = CoolPropMATLAB_wrap(121, self);
      else
        nargoutchk(0, 0)
        CoolPropMATLAB_wrap(122, self, varargin{1});
      end
    end
    function varargout = y(self, varargin)
      narginchk(1, 2)
      if nargin==1
        nargoutchk(0, 1)
        varargout{1} = CoolPropMATLAB_wrap(123, self);
      else
        nargoutchk(0, 0)
        CoolPropMATLAB_wrap(124, self, varargin{1});
      end
    end
    function self = GuessesStructure(varargin)
      if nargin~=1 || ~ischar(varargin{1}) || ~strcmp(varargin{1},'_swigCreate')
        % How to get working on C side? Commented out, replaed by hack below
        %self.swigInd = CoolPropMATLAB_wrap(125, varargin{:});
        tmp = CoolPropMATLAB_wrap(125, varargin{:}); % FIXME
        self.swigInd = tmp.swigInd;
        tmp.swigInd = uint64(0);
      end
    end
    function delete(self)
      if self.swigInd
        CoolPropMATLAB_wrap(126, self);
        self.swigInd=uint64(0);
      end
    end
  end
  methods(Static)
  end
end
