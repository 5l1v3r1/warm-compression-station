classdef SS < SwigRef
  methods
    function varargout = rhomolar(self, varargin)
      narginchk(1, 2)
      if nargin==1
        nargoutchk(0, 1)
        varargout{1} = CoolPropMATLAB_wrap(69, self);
      else
        nargoutchk(0, 0)
        CoolPropMATLAB_wrap(70, self, varargin{1});
      end
    end
    function varargout = T(self, varargin)
      narginchk(1, 2)
      if nargin==1
        nargoutchk(0, 1)
        varargout{1} = CoolPropMATLAB_wrap(71, self);
      else
        nargoutchk(0, 0)
        CoolPropMATLAB_wrap(72, self, varargin{1});
      end
    end
    function varargout = p(self, varargin)
      narginchk(1, 2)
      if nargin==1
        nargoutchk(0, 1)
        varargout{1} = CoolPropMATLAB_wrap(73, self);
      else
        nargoutchk(0, 0)
        CoolPropMATLAB_wrap(74, self, varargin{1});
      end
    end
    function varargout = hmolar(self, varargin)
      narginchk(1, 2)
      if nargin==1
        nargoutchk(0, 1)
        varargout{1} = CoolPropMATLAB_wrap(75, self);
      else
        nargoutchk(0, 0)
        CoolPropMATLAB_wrap(76, self, varargin{1});
      end
    end
    function varargout = smolar(self, varargin)
      narginchk(1, 2)
      if nargin==1
        nargoutchk(0, 1)
        varargout{1} = CoolPropMATLAB_wrap(77, self);
      else
        nargoutchk(0, 0)
        CoolPropMATLAB_wrap(78, self, varargin{1});
      end
    end
    function varargout = umolar(self, varargin)
      narginchk(1, 2)
      if nargin==1
        nargoutchk(0, 1)
        varargout{1} = CoolPropMATLAB_wrap(79, self);
      else
        nargoutchk(0, 0)
        CoolPropMATLAB_wrap(80, self, varargin{1});
      end
    end
    function varargout = Q(self, varargin)
      narginchk(1, 2)
      if nargin==1
        nargoutchk(0, 1)
        varargout{1} = CoolPropMATLAB_wrap(81, self);
      else
        nargoutchk(0, 0)
        CoolPropMATLAB_wrap(82, self, varargin{1});
      end
    end
    function self = SS(varargin)
      if nargin~=1 || ~ischar(varargin{1}) || ~strcmp(varargin{1},'_swigCreate')
        % How to get working on C side? Commented out, replaed by hack below
        %self.swigInd = CoolPropMATLAB_wrap(83, varargin{:});
        tmp = CoolPropMATLAB_wrap(83, varargin{:}); % FIXME
        self.swigInd = tmp.swigInd;
        tmp.swigInd = uint64(0);
      end
    end
    function varargout = is_valid(self,varargin)
      [varargout{1:max(1,nargout)}] = CoolPropMATLAB_wrap(84, self, varargin{:});
    end
    function delete(self)
      if self.swigInd
        CoolPropMATLAB_wrap(85, self);
        self.swigInd=uint64(0);
      end
    end
  end
  methods(Static)
  end
end
